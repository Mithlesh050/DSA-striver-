#include<bits/stdc++.h>
using namespace std ;
 
class Node{
    public :
     int data ;
     Node *left ;
     Node *right ;
     Node(int x){
        this->data=x ;
        this->left=NULL ;
        this->right=NULL ;
     }
};

Node *build(vector<int> &preorder , int prestart , int preend , vector<int> &inorder , int instart , int inend , unordered_map<int , int> &inmap){
    if(prestart>preend || instart>inend) return NULL ;
    Node *root=new Node(preorder[prestart]) ;
    int inroot=inmap[root->data] ;
    int numsleft=inroot-instart ;
    root->left=build(preorder , prestart+1 , prestart+numsleft , inorder , instart , inroot-1 , inmap) ;
    root->right=build(preorder , prestart+numsleft+1 , preend , inorder , inroot+1 , inend , inmap) ;
    return root ;
}

Node *buildTree(vector<int> &preorder , vector<int> &inorder){
    unordered_map<int , int> inmap ;
    for(int i=0 ; i<inorder.size() ; i++){
         inmap[inorder[i]]=i ;
        }
        Node *root=build(preorder , 0 , preorder.size()-1 , inorder , 0 , inorder.size()-1 , inmap) ;
    return root ;
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

int main(){
vector<int> inorder={9 , 3 , 15 , 20 , 7} ;
vector<int> preorder={3 , 9 , 20 , 15 , 7} ;
Node *tree=buildTree(preorder , inorder) ;
levelorder(tree) ;
return 0 ;
}