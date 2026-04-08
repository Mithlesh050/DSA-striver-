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

// TC --> O(n) && SC --> O(n) ;
/*
node *reverse_DLL(node *head) {
        stack<int> st ;
        node *temp=head ;
        while(temp){
            st.push(temp->data) ;
            temp=temp->next ;
        }
        temp=head ;
        while(temp){
            temp->data=st.top() ;
            st.pop() ;
            temp=temp->next ;
        }
        return head ;
    }
*/

    node *reverse_DLL(node *head) {
        if(head==NULL || head->next==NULL) return head ;
        node *last=NULL , *curr=head ;
        while(curr){
            last=curr->prev ;
            curr->prev=curr->next ;
            curr->next=last ;
            curr=curr->prev ;
        }
        return last->prev ;
    }

int main(){
vector<int> arr={1 , 2 , 3 , 4 , 5} ;
create_DLL(arr) ;
display(head) ;
cout<<endl ;
node *ans=reverse_DLL(head) ;
display(ans) ;
return 0 ;
}