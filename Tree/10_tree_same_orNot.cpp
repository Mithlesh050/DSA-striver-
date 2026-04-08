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

bool sameTree(Node *p , Node *q){
    if(p==NULL || q==NULL) return p==q ;
    return (p->data==q->data) && sameTree(p->left , q->left) && sameTree(p->right , q->right) ;
}

int main(){
Node *p=NULL , *q=NULL ;
p=create_tree(p) ;
q=create_tree(q) ;
cout<<sameTree(p , q) ;
return 0 ;
}