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

class nodeval{
    public :
    int maxnode ;
    int minnode ;
    int maxsize ;
    nodeval(int x , int y , int z){
        this->maxnode=y ;
        this->minnode=x ;
        this->maxsize=z ;
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

nodeval helper(Node *root){
    if(root==NULL) return nodeval(INT_MAX , INT_MIN , 0) ;
    auto left=helper(root->left) ;
    auto right=helper(root->right) ;
    if(left.maxnode<root->data && root->data<right.minnode){
        return nodeval(min(root->data , left.minnode) , max(root->data , right.maxnode) , (1+left.maxsize + right.maxsize)) ;
    }
    return nodeval(INT_MIN , INT_MAX , max(left.maxsize , right.maxsize)) ;
}

int largest_bst(Node *root){
    return helper(root).maxsize ;
}


int main(){
Node *root=NULL ;
root=create_tree(root) ;
cout<<largest_bst(root) ;
return 0 ;
}