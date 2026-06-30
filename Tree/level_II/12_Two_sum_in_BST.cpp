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

bool twoSum(Node *root , int k){
    vector<int> inorder ;
    Node *node=root ;
    stack<Node *> stk ;
    while(1){
        if(node){
            stk.push(node) ;
            node=node->left ;
        }
        else{
            if(stk.empty()) break;
            node=stk.top() ;
            stk.pop() ;
            inorder.push_back(node->data) ;
            node=node->right ;
        }
    }
    int l=0 , r=inorder.size()-1 ;
    while(l<r){
        if(inorder[l]+inorder[r]==k) return true ;
        else if(inorder[l]+inorder[r]>k) r-- ;
        else l++ ;
    }
    return false ;
}

int main(){
Node *root=NULL ;
root=create_tree(root) ;
cout<<twoSum(root , 6) ;
return 0 ;
}