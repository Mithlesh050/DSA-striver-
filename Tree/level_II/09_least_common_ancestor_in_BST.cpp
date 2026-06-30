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

Node *leastCommonAncestor(Node *root , Node *p , Node *q){
    if(root==NULL) return root ;
    if(root->data<p->data && root->data<q->data)
    return leastCommonAncestor(root->right , p , q) ;
    if(root->data>p->data && root->data>q->data)
    return leastCommonAncestor(root->left , p , q) ;
    return root ;
}

int main(){
Node *root=NULL ;
root=create_tree(root) ;
Node *ans=leastCommonAncestor(root , root->left->left->right , root->left->left->left) ;
cout<<ans->data ;
return 0 ;
}