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

int hight(Node *root){
    if(root == NULL) return 0 ;
    int lh=hight(root->left) ;
    int rh=hight(root->right) ;
   return 1+max(lh , rh) ;
}


int main(){
Node *root=NULL ;
root=create_tree(root) ;
cout<<hight(root) ;
return 0 ;
}