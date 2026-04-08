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

vector<int> top_view(Node *root){
    vector<int> ans ;
    queue<pair<Node * , int>> q ;
    map<int , int> mpp ;
    q.push({root , 0}) ;
    while(!q.empty()){
        auto p=q.front() ;
        q.pop() ;
        Node *node=p.first ;
        int level=p.second ;
        if(mpp.find(level)==mpp.end()) mpp[level]=node->data ;
        if(node->left) q.push({node->left , level-1}) ;
        if(node->right) q.push({node->right , level+1}) ;
    }
    for(auto p : mpp){
       ans.push_back(p.second) ;
    }
    return ans ;
}


int main(){
Node *root=NULL ;
root=create_tree(root) ;
cout<<"Top View  : " ;
vector<int> ans=top_view(root) ;
for(auto it : ans) cout<<it<<" " ;
return 0 ;
}