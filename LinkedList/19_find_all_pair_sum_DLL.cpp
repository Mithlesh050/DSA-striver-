#include<bits/stdc++.h>
using namespace std ;
struct node{
    node * prev ;
    int data ;
    node * next ;
}*head ;

void create_DLL(vector<int> &arr){
    node *temp , *last ;
    head=new node[sizeof(node)] ;
    head->prev=NULL ;
    head->data=arr[0] ;
    head->next=NULL ;
    last=head ;
    for(int i=1  ; i<arr.size() ; i++){
        temp=new node[sizeof(node)] ;
        temp->prev=last ;
        temp->data=arr[i] ;
        temp->next=NULL ;
        last->next=temp ;
        last=temp ;
    }
}
 
void display(node *p){
    while(p){
        cout<<p->data<<" " ;
        p=p->next ;
    }
}

vector<pair<int, int>> findPairsWithGivenSum(node *head, int target) {
        vector<pair<int , int>> ans ;
        node *left=head  , *right=head ;
        while(right->next) right=right->next ;
        while(left->data<right->data){
            if(left->data+right->data>target)
            right=right->prev ;
            else if(left->data+right->data<target)
            left=left->next ;
            else{
            ans.push_back({left->data , right->data}) ;
                left=left->next ;
                right=right->prev ;
            }
        }
        return ans ;
    }

int main(){
vector<int> arr={1 , 2 , 4 , 5 , 6 , 8 , 9} ;
int target=7 ;
create_DLL(arr) ;
display(head) ;
cout<<endl ;
vector<pair<int , int>> ans=findPairsWithGivenSum(head , target) ;
for(auto i:ans){
    cout<<"["<<i.first<< " , "<<i.second<< "]  ";
}
return 0 ;
}