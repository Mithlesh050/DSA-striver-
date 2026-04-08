#include<bits/stdc++.h>
using namespace std ;
struct Node{
     int key ;
     Node *next ;
}*head;
 
void create_ll(vector<int> &arr){
      struct Node * temp , *last ;
        head=new Node[sizeof(struct Node)] ;
        head->key=arr[0] ;
        head->next=NULL ;
        last=head ;
        for(int i=1 ; i<arr.size() ; i++){
            temp=new Node[sizeof(struct Node)] ;
            temp->key=arr[i] ;
            temp->next=NULL ;
            last->next=temp ;
            last=temp ;
        }
 }

void display(Node *p) {
    while(p){
        cout<<p->key<<" " ;
        p=p->next ;
    }
}

// TC --> O(n) (Itrative)
/*
void reverse_LL(Node *p){
    Node *temp=p , *curr=p->next , *currnext ;
    temp->next=NULL ;
    while(curr){
        currnext=curr->next ;
        curr->next=temp ;
        temp=curr ;
        curr=currnext ;
    }
    head=temp ;
}
*/

// Using recursion
Node *reverse_LL (Node *head){
    if(head==NULL || head->next==NULL) return head; 
    Node *newhead=reverse_LL(head->next) ;
    Node *front=head->next ;
    front->next=head ;
    head->next=NULL ;
    return newhead ;
}

int main(){
vector<int> arr={1 , 2 , 3 , 4 , 5} ;
create_ll(arr) ;
display(head) ;
cout<<endl ;
Node * ans=reverse_LL(head) ;
display(ans) ;
return 0 ;
}