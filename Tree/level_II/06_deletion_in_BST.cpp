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

Node *findlastright(Node *root){
    while(root->right)
    root=root->right ;
    return root ;
}

Node *helper(Node *root){
    if(root->left==NULL) return root->right ;
    else if(root->right==NULL) return root->left ;
    Node *rightchild=root->right ;
    Node *lastright=findlastright(root->left) ;
    lastright->right=rightchild ;
    return root->left ;
}

Node * deletion_in_BST(Node *root , int key){
    if(root==NULL) return root ;
    if(root->data==key) return helper(root) ;
    Node *ans=root ;
    while(root){
        if(root->data>key){
            if(root->left && root->left->data==key){
                root->left=helper(root->left) ;
                break; 
            }
            else root=root->left ;
        }
        else {
            if(root->right && root->right->data==key){
                root->right=helper(root->right) ;
                break; 
            }
            else root=root->right ;
        }
    }
    return ans ;
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

int main(){
Node *root=NULL ;
root=create_tree(root) ;
level_order(root) ;
int key=5 ;
Node *ans=deletion_in_BST(root , key) ;
cout<<"After deletion of node "<<key<<endl ;
level_order(ans) ;
return 0 ;
}