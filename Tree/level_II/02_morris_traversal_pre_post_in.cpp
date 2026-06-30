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

vector<int> inorder(Node *root){
    vector<int> ans ;
    Node *curr=root ;
    while(curr){
        if(curr->left==NULL){
            ans.push_back(curr->data) ;
            curr=curr->right ;
        }
        else{
            Node *prev=curr->left ;
            while(prev->right && prev->right!=curr) prev=prev->right ;
            if(prev->right==NULL){
                prev->right=curr ;
                curr=curr->left ;
            }
            else{
                prev->right=NULL ;
                ans.push_back(curr->data) ;
                curr=curr->right ;
            }
        }
    }
    return ans ;
}

vector<int> preorder(Node *root){
    vector<int> ans ;
    Node *curr=root ;
    while(curr){
        if(curr->left==NULL){
            ans.push_back(curr->data) ;
            curr=curr->right ;
        }
        else{
            Node *prev=curr->left ;
            while(prev->right && prev->right!=curr) prev=prev->right ;
            if(prev->right==NULL){
                prev->right=curr ;
                ans.push_back(curr->data) ;
                curr=curr->left ;
            }
            else{
                prev->right=NULL ;
                curr=curr->right ;
            }
        }
    }
    return ans ;
}

int main(){
Node *root=NULL ;
root=create_tree(root) ;
cout<<"Inorder Traversal : " ;
vector<int> ans=inorder(root) ;
for(auto it : ans) cout<<it<<" " ;
cout<<endl ;
cout<<"Preorder Traversal : " ;
vector<int> pre=preorder(root) ;
for(auto it : pre) cout<<it<<" " ;
return 0 ;
}