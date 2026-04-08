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

bool isleaf(Node *root){
    if(root->left==NULL && root->right==NULL) return true ;
    return false ;
}

void addleftnodes(Node *root , vector<int> &arr){
    Node *curr=root->left ;
    while(curr){
        if(!isleaf(curr)) arr.push_back(curr->data) ;
        if(curr->left) curr=curr->left ;
        else curr=curr->right ;
    }
}

void addrightnodes(Node *root , vector<int> &arr){
    Node *curr=root->right ;
    stack<int> st ;
    while(curr){
        if(!isleaf(curr)) st.push(curr->data) ;
        if(curr->right) curr=curr->right ;
        else curr=curr->left ;
    }
    while(!st.empty()){
        int temp=st.top() ;
        st.pop() ;
        arr.push_back(temp) ;
    }
}

void addleafnodes(Node *root , vector<int> &arr){
    if(isleaf(root)){
       arr.push_back(root->data) ;
       return ;
    } 
    if(root->left) addleafnodes(root->left , arr) ;
    if(root->right) addleafnodes(root->right , arr) ;
}

vector<int> boundary(Node *root){
    vector<int> ans ;
    if(root==NULL) return ans ;
    if(!isleaf(root)) ans.push_back(root->data) ;
    addleftnodes(root , ans) ;
    addleafnodes(root , ans) ;
    addrightnodes(root , ans) ;
    return ans ;
}


int main(){
Node *root=NULL ;
root=create_tree(root) ;
cout<<"Boundary(anticlockwise)  : " ;
vector<int> ans=boundary(root) ;
for(auto it : ans) cout<<it<<" " ;
return 0 ;
}