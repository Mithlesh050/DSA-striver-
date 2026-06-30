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

Node *build(vector<int> &postorder , int poststart , int postend , vector<int> &inorder , int instart , int inend , unordered_map<int , int> &inmap){
    if(poststart>postend || instart>inend) return NULL ;
    Node *root=new Node(postorder[postend]) ;
    int inroot=inmap[root->data] ;
    int numsleft=inend - inroot ;
    root->left=build(postorder , poststart , postend-numsleft-1 , inorder , instart , inroot-1 , inmap) ;
    root->right=build(postorder , postend-numsleft , postend-1 , inorder , inroot+1 , inend , inmap) ;
    return root ;
}

Node *buildTree(vector<int> &postorder , vector<int> &inorder){
    unordered_map<int , int> inmap ;
    for(int i=0 ; i<inorder.size() ; i++){
         inmap[inorder[i]]=i ;
        }
        Node *root=build(postorder , 0 , postorder.size()-1 , inorder , 0 , inorder.size()-1 , inmap) ;
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
vector<int> postorder={9 , 15 , 7 , 20 , 3} ;
Node *tree=buildTree(postorder , inorder) ;
levelorder(tree) ;
return 0 ;
}