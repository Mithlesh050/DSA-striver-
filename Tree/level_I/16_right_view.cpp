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

void traverse(Node *root , vector<int> &arr , int level){
    if(root==NULL) return ;
    if(level==arr.size()) arr.push_back(root->data) ;
    traverse(root->right , arr , level+1) ;
    traverse(root->left , arr , level+1) ;
}

vector<int> right_view(Node *root){
    vector<int> ans ;
    traverse(root , ans , 0) ;
    return ans ;
}


int main(){
Node *root=NULL ;
root=create_tree(root) ;
cout<<"Right View  : " ;
vector<int> ans=right_view(root) ;
for(auto it : ans) cout<<it<<" " ;
return 0 ;
}