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

void delete_element(node *p , int index){
    node *temp=head ;
    if(index==1){
        head=head->next ;
        head->prev=NULL ;
        delete(temp) ;
    }
    else{
        for(int i=1 ; i<index-1 ; i++){
            p=p->next ;
        }
        temp=p->next ;
        p->next=temp->next ;
        if(temp->next!=NULL) temp->next->prev=p->next ;
        delete(temp) ;
    }
}

int main(){
vector<int> arr={1 , 2 , 3 , 4 , 5} ;
create_DLL(arr) ;
display(head) ;
cout<<endl ;
delete_element(head , 5) ;
display(head) ;
return 0 ;
}