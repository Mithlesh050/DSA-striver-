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

int floor_in_BST(Node *root , int val){
    int x=-1 ;
    Node *temp=root ;
    while(temp){
        if(temp->data==val){
            x=temp->data ;
            return x ;
        }
        if(val>temp->data){
            x=temp->data ;
            temp=temp->right ;
        }
        else
        temp=temp->right ;
    }
    return x ;
}

int main(){
Node *root=NULL ;
root=create_tree(root) ;
cout<<floor_in_BST(root , 6) ;
return 0 ;
}