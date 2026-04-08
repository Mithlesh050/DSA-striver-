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

vector<vector<int>> virtical_order(Node *root){
    vector<vector<int>> ans ;
    queue<pair<Node * , pair<int , int>>> q ;
    map<int , map<int , multiset<int>>> mpp ;
    q.push({root , {0 , 0}}) ;
    while(!q.empty()){
        auto p=q.front() ;
        q.pop() ;
        Node *node=p.first ;
        int vertical=p.second.first , level=p.second.second ;
        mpp[vertical][level].insert(node->data) ;
        if(node->left) q.push({node->left , {vertical-1 , level+1}}) ;
        if(node->right) q.push({node->right , {vertical+1 , level+1}}) ;
    }
    for(auto p : mpp){
        vector<int> vertic ;
        for(auto q : p.second){
            vertic.insert(vertic.end() , q.second.begin() , q.second.end()) ;
        }
        ans.push_back(vertic) ;
    }
    return ans ;
}


int main(){
Node *root=NULL ;
root=create_tree(root) ;
cout<<"Virtical Order Traversal  : " <<endl ;
vector<vector<int>> ans=virtical_order(root) ;
for(int i=0 ; i<ans.size() ; i++){
    for(int j=0 ; j<ans[i].size() ; j++){
        cout<<ans[i][j]<<" " ;
    }
    cout<<endl ;
}
return 0 ;
}