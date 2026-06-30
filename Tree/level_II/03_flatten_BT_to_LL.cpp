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

void levelorder(Node *root){
    queue<Node *> q ;
    q.push(root) ;
    while(!q.empty()){
        int n=q.size() ;
        for(int i=0 ; i<n ; i++){
            Node *node=q.front() ;
            q.pop() ;
            if(node->left) q.push(node->left) ;
            if(node->right) q.push(node->right) ;
            cout<<node->data<<" " ;
        }
        cout<<endl ;
    }
}

//recursive 
/*
void flat(Node *root , Node* &prev){
    if(root==NULL) return ;
    flat(root->right , prev) ;
    flat(root->left , prev) ;
    root->right=prev ;
    root->left=NULL ;
    prev=root ;
}

// TC --> O(n) && SC --> O(n)
void flatten(Node *root){
    Node *prev=NULL ;
    flat(root , prev) ;
}
*/

// iterative 
/*
void flatten(Node *root){
    stack<Node *> st ;
    st.push(root) ;
    while(!st.empty()){
        Node *curr=st.top() ;
        st.pop() ;
        if(curr->right) st.push(curr->right) ;
        if(curr->left) st.push(curr->left) ;
        if(!st.empty()){
            curr->right=st.top() ;
            curr->left=NULL ;
        }
    }
}
*/

// 3rd approach
void flatten(Node *root){
     Node *curr=root , *prev ;
     while(curr){
        if(curr->left){
            prev=curr->left ;
            while(prev->right) prev=prev->right ;
            prev->right=curr->right ;
            curr->right=curr->left ;
            curr->left=NULL ;
        }
        curr=curr->right ;
     }
}

int main(){
Node *root=NULL ;
root=create_tree(root) ;
flatten(root) ;
levelorder(root) ;
return 0 ;
}