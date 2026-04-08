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

// TC --> O(n) && SC --> O(n)
vector<vector<int>> zig_zag(Node *root){
    vector<vector<int>> ans ;
    bool ltr=true ;
    queue<Node *> q ;
    q.push(root) ;
    while(!q.empty()){
        int size=q.size() ;
        vector<int> row(size) ;
        for(int i=0 ; i<size ; i++){
            Node *node=q.front() ;
            q.pop() ;
            int index=ltr? i : size-1-i ;
            row[index]=node->data ;
            if(node->left) q.push(node->left) ;
            if(node->right) q.push(node->right) ;
        }
        ltr=!ltr ;
        ans.push_back(row) ;
    }
    return ans ;
}

int main(){
Node *root=NULL ;
root=create_tree(root) ;
cout<<"Zig-Zag Traversal : "<<endl ;
vector<vector<int>> ans=zig_zag(root) ;
for(int i=0 ; i<ans.size() ; i++){
    for(int j=0 ; j<ans[i].size() ; j++){
        cout<<ans[i][j]<<" " ;
    }
    cout<<endl ;
}
return 0 ;
}