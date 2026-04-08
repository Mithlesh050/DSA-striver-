#include<bits/stdc++.h>
using namespace std ;

struct node{
    int data ;
    node *next ;
}*head ;

void create_ll(vector<int> &arr){
    node *temp , *last ;
    head=new node[sizeof(node)] ;
    head->data=arr[0] ;
    head->next=NULL ;
    last=head ;
    for(int i=1 ; i<arr.size() ; i++){
        temp=new node[sizeof(node)] ;
        temp->data=arr[i] ;
        temp->next=NULL ;
        last->next=temp ;
        last=temp ;
    }
}
 
void display_ll(node *p){
    while(p){
        cout<<p->data<<" " ;
        p=p->next ;
    }
}

node * insert_element(node *head , int key , int position){
    node *temp , *prev=head ;
    if(position==1){
        temp=new node[sizeof(node)] ;
        temp->data=key ;
        temp->next=head ;
        head=temp ;
    }
    else{
        for(int i=1 ; i<position-1 ; i++){
           prev=prev->next ;
        }
        temp=new node[sizeof(node)] ;
        temp->data=key ;
        temp->next=prev->next ;
        prev->next=temp ;
    }
    return head ;
}

int main(){
vector<int> arr={1 , 2 , 3 , 4 , 5} ;
create_ll(arr) ;
display_ll(head) ;
cout<<endl ;
head=insert_element(head , 6 , 6) ;
display_ll(head) ;
return 0 ;
}