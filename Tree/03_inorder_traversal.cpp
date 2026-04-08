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

// recursive
/*
void inorder(Node *root){
    if(root==NULL) return  ;
    inorder(root->left) ;
    cout<<root->data<<" " ;
    inorder(root->right) ;
}
*/

// iterative
void inorder(Node *root){
    stack<Node *> stk ;
    Node *node=root ;
    while(1){
        if(node){
            stk.push(node) ;
            node=node->left ;
        }
        else{
            if(stk.empty()==true) break; 
            node=stk.top() ;
            stk.pop() ;
            cout<<node->data<<" " ;
            node=node->right ;
        }
    }
}

int main(){
Node *root=NULL ;
root=create_tree(root) ;
cout<<"Inorder Traversal : " ;
inorder(root) ;
return 0 ;
}