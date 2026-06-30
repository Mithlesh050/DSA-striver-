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

int findSuccessor(Node *root , Node *x , int &ans){
        if(root==NULL) return ans ;
        if(root->data>x->data){
            ans=root->data ;
           findSuccessor(root->left , x , ans) ;
        } 
        else findSuccessor(root->right , x , ans) ;
        return ans ;
    }
    int inOrderSuccessor(Node *root, Node *x) {
        int ans=-1 ;
        findSuccessor(root , x , ans) ;
        return ans ;
    }

int main(){
Node *root=NULL ;
root=create_tree(root) ;
cout<<inOrderSuccessor(root , root->left->right) ;
return 0 ;
}