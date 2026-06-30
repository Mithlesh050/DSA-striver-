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

Node *build(vector<int> &arr , int &i , int bound){
    if(i==arr.size() || arr[i]>bound) return NULL ;
    Node *root=new Node(arr[i++]) ;
    root->left=build(arr , i , root->data) ;
    root->right=build(arr , i , bound) ;
    return root ;
}

Node *bstFromPreorder(vector<int> &preorder){
    int i=0 ;
    return build(preorder , i , INT_MAX) ;
}

void level_order(Node *root){
    queue<Node *> q ;
    q.push(root) ;
    while(!q.empty()){
        int size=q.size() ;
        for(int i=0 ; i<size ; i++){
            Node *node=q.front() ;
            q.pop() ;
            cout<<node->data<<" " ;
            if(node->left) q.push(node->left) ;
            if(node->right) q.push(node->right) ;
        }
        cout<<endl ;
    }
}

int main(){
vector<int> preorder={8 , 5 , 3  , 10 , 9 , 11} ;
Node *root=bstFromPreorder(preorder) ;
level_order(root) ;
return 0 ;
}