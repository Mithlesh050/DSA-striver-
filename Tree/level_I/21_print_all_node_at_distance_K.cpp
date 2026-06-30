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

void parent_tracker(Node *root , unordered_map<Node * , Node *> &parent ){
    queue<Node *> q ;
    q.push(root) ;
    while(!q.empty()){
        Node *node=q.front() ;
        q.pop() ;
        if(node->left){
            parent[node->left]=node ;
            q.push(node->left) ;
        }
        if(node->right){
            parent[node->right]=node ;
            q.push(node->right) ;
        }
    }
}

vector<int> Nodes_at_distance_k(Node *root , Node *target , int k){
    vector<int> ans ;
    unordered_map<Node * , Node *> parent ;
    parent_tracker(root ,  parent) ;
        queue<Node *> q ;
        q.push(target) ;
        unordered_map<Node * , bool> visited ;
        visited[target]=true ;
        int level=0 ;
        while(!q.empty()){
            int size=q.size() ;
            if(level==k) break;
            for(int i=0 ; i<size ; i++){
                Node *node=q.front() ;
                q.pop() ;
                if(node->left && !visited[node->left]){
                    visited[node->left]=true ;
                    q.push(node->left) ;
                }
                if(node->right && !visited[node->right]){
                    visited[node->right]=true ;
                    q.push(node->right) ;
                }
                if(parent[node] && !visited[parent[node]]){
                    visited[parent[node]]=true ;
                    q.push(parent[node]) ;
                }
            }
            level++ ;
        }
        while(!q.empty()){
            Node *node=q.front() ;
            q.pop() ;
            ans.push_back(node->data) ;
        }
    return ans ;
}


int main(){
Node *root=NULL ;
root=create_tree(root) ;
cout<<"All Nodes at distance k  : " ;
int k=2 ;
vector<int> ans=Nodes_at_distance_k(root , root->left , k) ;
for(auto it : ans) cout<<it<<" " ;
return 0 ;
}