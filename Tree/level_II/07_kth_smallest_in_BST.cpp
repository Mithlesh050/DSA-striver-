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

int kth_smallest(Node *root , int k){
    Node *node=root ;
    stack<Node *> stk ;
    int count=0 ;
    while(1){
        if(node){
            stk.push(node) ;
            node=node->left ;
        }
        else{
            if(stk.empty()==true) break; 
            node=stk.top() ;
            stk.pop() ;
            count++ ;
            if(count==k-1)
            return node->data ;
            node=node->right ;
        }
    }
    return 0 ;
}

int main(){
Node *root=NULL ;
root=create_tree(root) ;
int k=5 ;
cout<<kth_smallest(root , k) ;
return 0 ;
}