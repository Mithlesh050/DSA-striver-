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

bool check(Node *left , Node *right){
    if(left==NULL || right==NULL) return left==right ;
    if(left->data!=right->data) return false ;
    return check(left->left , right->right) && check(left->right , right->left) ;
}

bool isSymmetric(Node *root){
    if(root==NULL) return true ;
    return check(root->left , root->right) ;
}

int main(){
Node *root=NULL ;
root=create_tree(root) ;
cout<<"Symmetric or Not  : "<<isSymmetric(root) ;

return 0 ;
}