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

// TC --> O(n^2) 
/*
int hight(Node *root){
    if(root == NULL) return 0 ;
    int lh=hight(root->left) ;
    int rh=hight(root->right) ;
   return 1+max(lh , rh) ;
}

bool balanceOrNot(Node *root){
    if(root == NULL) return 1 ;
    int lh=hight(root->left) ;
    int rh=hight(root->right) ;
    if(abs(lh-rh)>1) return false ;
    bool left=balanceOrNot(root->left) ;
    bool right=balanceOrNot(root->right) ;
    if(!left || !right) return false ;
    return true ;
}
*/

int check(Node *root){
    if(root == NULL) return 0 ;
    int lh=check(root->left) ;
    if(lh==-1) return -1 ;
    int rh=check(root->right) ;
    if(rh==-1) return -1 ;
    if(abs(lh-rh)>1) return -1 ;
   return 1+max(lh , rh) ;
}
 
// TC --> O(n)
bool balanceOrNot(Node *root){
    int test=check(root) ;
    if(test==-1) return false;
    return true ;
}

int main(){
Node *root=NULL ;
root=create_tree(root) ;
cout<<balanceOrNot(root) ;
return 0 ;
}