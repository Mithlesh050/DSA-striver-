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

node *remove_duplicate(node *head){
    node *temp=head ;
    while(temp->next){
        if(temp->data==temp->next->data){
            node *p=temp->next ;
            temp->next=p->next ;
            if(p->next)
            p->next->prev=temp ;
            delete p ;
        }
        else
        temp=temp->next ;
    }
   return head ;
}

int main(){
vector<int> arr={1 , 1 , 1 , 2 , 3 , 3 , 4} ;
int target=7 ;
create_DLL(arr) ;
display(head) ;
cout<<endl ;
node *ans=remove_duplicate(head) ;
display(ans) ;
return 0 ;
}