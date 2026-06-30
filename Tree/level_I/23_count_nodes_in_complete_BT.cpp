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

int leftHight(Node *root){
    int lh=0 ;
    while(root){
        lh++ ;
        root=root->left ;
    }
    return lh ;
}

int rightHight(Node *root){
    int rh=0 ;
    while(root){
        rh++ ;
        root=root->right ;
    }
    return rh ;
}

// TC --> O((logn)^2)
int countNodes(Node *root){
    if(root==NULL) return 0 ;
    int lh=leftHight(root) ;
    int rh=rightHight(root) ;
    if(lh==rh) return (1<<lh)-1 ;
    return 1+countNodes(root->left)+countNodes(root->right) ;
}


int main(){
Node *root=NULL ;
root=create_tree(root) ;
cout<<"Number of nodes in complete Binary Tree : "<<countNodes(root) ;
return 0 ;
}