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

bool validate(Node *root , long long mini , long long maxi){
     if(root==NULL) return true ;
     if(root->data>=maxi || root->data<=mini) return false ;
     return validate(root->left , mini , root->data) && validate(root->right , root->data , maxi) ;
}

bool isBST(Node *root){
    return validate(root , LLONG_MIN , LLONG_MAX) ;
}

int main(){
Node *root=NULL ;
root=create_tree(root) ;
cout<<isBST(root) ;
return 0 ;
}