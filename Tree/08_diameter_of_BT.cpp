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
int maxi=-1 ;
int diameter(Node *root){
    if(root == NULL) return 1 ;
    int lh=hight(root->left) ;
    int rh=hight(root->right) ;
    maxi=max(maxi , lh+rh) ;
    diameter(root->left) ;
    diameter(root->right) ;
    return maxi ;
}
*/

int hight(Node *root , int *maxi){
    if(root == NULL) return 0 ;
    int lh=hight(root->left , maxi) ;
    int rh=hight(root->right , maxi) ;
    *maxi=max(*maxi , lh+rh) ;
   return 1+max(lh , rh) ;
}
 
// TC --> O(n)
int diameter(Node *root){
   int maxi=-1 , *ptr=&maxi;
   hight(root , ptr) ;
   return maxi;
}

int main(){
Node *root=NULL ;
root=create_tree(root) ;
cout<<diameter(root) ;
return 0 ;
}