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


// TC --> O(3n) && SC --> O(3n)
vector<vector<int>> traversal(Node *root){
    vector<vector<int>> ans ;
    vector<int> pre , in , post ;
    stack<pair<Node * , int>> st ;
    st.push({root , 1}) ;
    while(!st.empty()){
        auto it=st.top() ;
        st.pop() ;
        if(it.second==1){
           pre.push_back(it.first->data) ;
           it.second++ ;
           st.push(it) ;
           if(it.first->left){
            st.push({it.first->left , 1}) ;
           }
        }
        else if(it.second==2){
            in.push_back(it.first->data) ;
            it.second++ ;
            st.push(it) ;
            if(it.first->right){
                st.push({it.first->right , 1}) ;
            }
        }
        else{
            post.push_back(it.first->data) ;
        }
    }
    ans.push_back(pre) ;
    ans.push_back(in) ;
    ans.push_back(post) ;
    return ans ;
}


int main(){
Node *root=NULL ;
root=create_tree(root) ;
vector<vector<int>> ans = traversal(root) ;
cout<<"Preorder Traversal : " ;
for(int i=0 ; i<ans[0].size() ; i++) cout<<ans[0][i]<<" " ;
cout<<endl ;
cout<<"Inorder Traversal : " ;
for(int i=0 ; i<ans[1].size() ; i++) cout<<ans[1][i]<<" " ;
cout<<endl ;
cout<<"Postorder Traversal : " ;
for(int i=0 ; i<ans[2].size() ; i++) cout<<ans[2][i]<<" " ;
cout<<endl ;
return 0 ;
}