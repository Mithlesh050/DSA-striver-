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

// recursive
/*
void postorder(Node *root){
    if(root==NULL) return  ;
    postorder(root->left) ;
    postorder(root->right) ;
    cout<<root->data<<" " ;
}
*/

// iterative with 2 stack
/*
void postorder(Node *root){
    stack<Node *> st1 , st2 ;
    st1.push(root) ;
    while(!st1.empty()){
        Node *node=st1.top() ;
        st1.pop() ;
        st2.push(node) ;
        if(node->left) st1.push(node->left) ;
        if(node->right) st1.push(node->right) ;
    }
    while(!st2.empty()){
        cout<<st2.top()->data<<" " ;
        st2.pop() ;
    }
}
*/

// iterative with 1 stack 
void postorder(Node *root){
    Node *curr=root , *temp ;
    stack<Node *> st ;
    while(curr || !st.empty()){
        if(curr){
            st.push(curr) ;
            curr=curr->left ;
        }
        else{
            temp=st.top()->right ;
            if(temp==NULL){
                temp=st.top() ;
                st.pop() ;
                cout<<temp->data<<" " ;
                while(!st.empty() && temp==st.top()->right){
                    temp=st.top() ;
                    st.pop() ;
                    cout<<temp->data<<" " ;
                }
            }
            else
            curr=temp ;
        }
    }
}

int main(){
Node *root=NULL ;
root=create_tree(root) ;
cout<<"Postorder Traversal : " ;
postorder(root) ;
return 0 ;
}