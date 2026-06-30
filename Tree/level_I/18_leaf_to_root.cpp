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

vector<int> rootToLeaf(Node *root , int leaf){
      vector<int> ans ;
      if(root==NULL) return ans ;
      find_path(root , ans , leaf) ;
      return ans ;
}

int main(){
Node *root=NULL ;
root=create_tree(root) ;
cout<<"Root to leaf path : " ;
int leaf=7 ;
vector<int> ans = rootToLeaf(root , leaf) ;
for(auto it : ans) cout<<it<<" --> " ;
return 0 ;
}