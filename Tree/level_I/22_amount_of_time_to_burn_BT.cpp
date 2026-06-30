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

Node * parent_tracker(Node *root , unordered_map<Node * , Node *> &parent , int start){
        Node *res ;
        queue<Node *> q ;
        q.push(root) ;
        while(!q.empty()){
            Node *node=q.front() ;
            q.pop() ;
            if(node->data==start) res=node ;
            if(node->left){
                parent[node->left]=node ;
                q.push(node->left) ;
            }
            if(node->right){
                parent[node->right]=node ;
                q.push(node->right) ;
            }
        }
        return res ;
    }
    
    int amountOfTime(Node* root, int start) {
        int level=-1 ;
        unordered_map<Node * , Node *> parent ;
        Node *starting_node=parent_tracker(root , parent , start) ;
        queue<Node *> q ;
        q.push(starting_node) ;
        unordered_map<Node * , bool > visited ;
        visited[starting_node]=true ;
        while(!q.empty()){
            int size=q.size() ;
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
        return level ;
    }


int main(){
Node *root=NULL ;
root=create_tree(root) ;
int start=5 ;
cout<<"Time to burn BT  : "<<amountOfTime(root , start);
return 0 ;
}