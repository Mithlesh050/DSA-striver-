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

node * delete_elements(node *head , int key){
    node * temp=head ;
    while(temp){
        if(temp->data==key){
            if(temp==head){
                head=head->next ;
            }
            node *prevnode=temp->prev  , *nextnode=temp->next ;
            if(nextnode!=NULL) nextnode->prev=prevnode ;
            if(prevnode!=NULL) prevnode->next=nextnode ;
            delete temp ;
            temp=nextnode ;
        }
        else temp=temp->next ;
    }
   return head ;
}

int main(){
vector<int> arr={1 , 2 , 3 , 4 , 5 , 2} ;
create_DLL(arr) ;
display(head) ;
cout<<endl ;
node * ans=delete_elements(head , 2) ;
display(ans) ;
return 0 ;
}