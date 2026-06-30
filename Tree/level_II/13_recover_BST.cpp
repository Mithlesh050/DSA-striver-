#include<bits/stdc++.h>
using namespace std ;
 
class Node {
    public :
    int data ;
    Node *left ;
    Node *right ;

    Node(int d){
        this->data=d ;
        this->left=NULL  ;
        this->right=NULL ;
    }
};

Node *create_tree(Node *root){
    if(root==NULL)
    cout<<" node : " ;
    int d ;
    cin>>d ;
    root=new Node(d) ;
    if(d==-1) return NULL ;
    cout<<"Enter left child of "<<d ;
    root->left=create_tree(root->left);
    cout<<"Enter right child of "<<d ;
    root->right=create_tree(root->right) ;
}

void level_order(Node *root){
    queue<Node *> q ;
    q.push(root) ;
    while(!q.empty()){
        int size=q.size() ;
        for(int i=0 ; i<size ; i++){
            Node *node=q.front() ;
            q.pop() ;
            cout<<node->data<<" " ;
            if(node->left) q.push(node->left) ;
            if(node->right) q.push(node->right) ;
        }
        cout<<endl ;
    }
}

void inorder(Node *root , Node *&prev , Node *&first , Node *&middle , Node *&last){
    if(root==NULL) return ;
    inorder(root->left , prev , first , middle , last) ;
    if(prev && (prev->data>root->data)){
        if(first==NULL){
           first=prev ;
           middle=root ;
        }
        else
           last=root ;
    }
    prev=root ;
    inorder(root->right , prev , first , middle , last) ;
}
void recover(Node *root){
     Node *first=NULL ;
     Node *middle=NULL ;
     Node *last=NULL ;
     Node *prev=new Node(INT_MIN) ;
     inorder(root , prev , first , middle , last) ;
     if(first && last) swap(first->data , last->data) ;
     else if(first && middle) swap(first->data , middle->data) ;
}

int main(){
Node *root=NULL ;
root=create_tree(root) ;
cout<<"Before recovery : "<<endl ;
level_order(root) ;
recover(root) ;
cout<<"After recovery : "<<endl ;
level_order(root) ;
return 0 ;
}