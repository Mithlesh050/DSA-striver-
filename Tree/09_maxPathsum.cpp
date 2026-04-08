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

int pathsum(Node *root , int *maxi){
    if(root == NULL) return 0 ;
    int lh=max(0 , pathsum(root->left , maxi));
    int rh=max(0 , pathsum(root->right , maxi)) ;
    *maxi=max(*maxi , lh+rh+root->data) ;
   return root->data+max(lh , rh) ;
}
 
// TC --> O(n)
int maxPathsum(Node *root){
   int maxi=-1 , *ptr=&maxi;
   pathsum(root , ptr) ;
   return maxi;
}

int main(){
Node *root=NULL ;
root=create_tree(root) ;
cout<<maxPathsum(root) ;
return 0 ;
}