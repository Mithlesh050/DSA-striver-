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
void preorder(Node *root){
    if(root==NULL) return ;
    cout<<root->data<<" " ;
    preorder(root->left) ;
    preorder(root->right) ;
}
*/

//iterative
void preorder(Node *root){
    stack<Node *> stk ;
    stk.push(root) ;
    while(!stk.empty()){
        Node *node=stk.top() ;
        stk.pop() ;
        cout<<node->data<<" " ;
        if(node->right) stk.push(node->right) ;
        if(node->left) stk.push(node->left) ;
    }
}

int main(){
Node *root=NULL ;
root=create_tree(root) ;
cout<<"Preorder Traversal : " ;
preorder(root) ;
return 0 ;
}