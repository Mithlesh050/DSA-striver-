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

string serialize(Node *root){
    string str="" ;
    if(root==NULL) return str ;
    queue<Node *> q ;
    q.push(root) ;
    while(!q.empty()){
        Node *node=q.front() ;
        q.pop() ;
        if(node==NULL) str.append("*,") ;
        else str.append(to_string(node->data)+',') ;
        if(node){
            q.push(node->left) ;
            q.push(node->right) ;
        }
    }
    return str ;
}

Node *deserialize(string data){
    if(data.length()==0) return NULL ;
    stringstream s(data) ;
    string str ;
    getline(s , str , ',') ;
    Node *root=new Node(stoi(str)) ;
    queue<Node *> q ;
    q.push(root) ;
    while(!q.empty()){
        Node *node=q.front() ;
        q.pop() ;
        getline(s , str , ',') ;
        if(str=="*") node->left=NULL ;
        else{
            Node *leftnode=new Node(stoi(str)) ;
            node->left=leftnode ;
            q.push(leftnode);
        }
        getline(s , str , ',') ;
        if(str=="*") node->right=NULL ;
        else{
            Node *rightnode=new Node(stoi(str)) ;
            node->right=rightnode ;
            q.push(rightnode);
        }
    }
    return root ;
}

int main(){
Node *root=NULL ;
root=create_tree(root) ;
string s=serialize(root) ;
cout<<"["<<s<<"]"<<endl ;
Node *ans=deserialize(s) ;
levelorder(ans) ;
return 0 ;
}