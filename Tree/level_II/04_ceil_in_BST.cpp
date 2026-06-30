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

int ceil_in_BST(Node *root , int val){
    int x=INT_MAX ;
    Node *temp=root ;
    while(temp){
        if(temp->data>val){
            if(temp->data<x) x=temp->data ;
            temp=temp->left ;
        }
        else{
            if(temp->data<x && temp->data>=val) x=temp->data ;
            temp=temp->right ;
        }
    }
    return x ;
}

int main(){
Node *root=NULL ;
root=create_tree(root) ;
cout<<ceil_in_BST(root , 6) ;
return 0 ;
}