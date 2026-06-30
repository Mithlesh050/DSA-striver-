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

bool find_path(Node *root , vector<int> &arr , int leaf) {
     if(root==NULL) return false ;
     arr.push_back(root->data) ;
     if(root->data==leaf) return true ;
     if(find_path(root->left , arr , leaf) || find_path(root->right , arr , leaf))
     return true ;
     arr.pop_back() ;
     return false ;
}

Node *find_LCA(Node *root , int p , int q , int *ans){
    if(root==NULL || root->data==p || root->data==q){
        *ans=root->data ;
        return root ;
    }
    Node *left=find_LCA(root->left , p , q , ans) ;
    Node *right=find_LCA(root->right , p , q , ans) ;
    if(left==NULL){
        *ans=right->data ;
        return right ;
    }
    else if(right==NULL){
        *ans=left->data ;
        return left ;
    }
    else {
        *ans=root->data ;
         return root ;
    }
}
int LCA (Node *root , int p , int q){
    int ans=0 , *ptr=&ans ;
    find_LCA(root , p , q , ptr) ;
    return ans ;
}

int main(){
Node *root=NULL ;
root=create_tree(root) ;
int p=7 , q=3 ;
cout<<"Lowest_common ancestor  : " <<LCA(root , p , q);
return 0 ;
}