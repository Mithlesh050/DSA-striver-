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

int max_width(Node *root){
    int ans=0 ;
    queue<pair<Node * , int >> q ;
    q.push({root , 0}) ;
    while(!q.empty()){
        int size=q.size() ;
        int min=q.front().second ;
        int first , last ;
        for(int i=0 ; i<size ; i++){
            auto p=q.front() ;
            q.pop() ;
            int curr_id=p.second-min ;
            Node *node=p.first ;
            if(i==0) first=curr_id ;
            if(i==size-1) last=curr_id ;
            if(node->left) q.push({node->left , 2*curr_id+1}) ;
            if(node->right) q.push({node->right , 2*curr_id+2}) ;
        }
        ans=max(ans , last-first+1) ;
    }
    return ans ;
}

int main(){
Node *root=NULL ;
root=create_tree(root) ;
cout<<"Maximum width  : " <<max_width(root);
return 0 ;
}