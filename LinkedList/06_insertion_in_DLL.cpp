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
 
void insert_element(node *p , int key , int position){
    node *temp=new node;
    temp->data=key ;
    if(position==1){
        temp->next=head ;
        temp->prev=NULL ;
        head->prev=temp->next ;
        head=temp ;
    }
    else{
        for(int i=1 ; i<position-1 ; i++){
            p=p->next ;
        }
        temp->next=p->next ;
        temp->prev=p ;
        if(p->next)
        p->next->prev=temp ;
        p->next=temp ;
    }
}

void display(node *p){
    while(p){
        cout<<p->data<<" " ;
        p=p->next ;
    }
}

int main(){
vector<int> arr={1 , 2 , 3 , 4 , 5} ;
create_DLL(arr) ;
display(head) ;
cout<<endl ;
insert_element(head , 6 ,1) ;
display(head) ;
return 0 ;
}