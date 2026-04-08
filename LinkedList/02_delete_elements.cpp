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

void delete_element(node *v , int index){
    if(v==NULL){
        cout<<"List is empty"<<endl ;
        return ;
    }
    node *temp ;
    if(index==1){
        temp=head ;
        head=head->next ;
        delete temp ;
    }
    else{
        temp=head ;
        for(int i=1 ; i<index ; i++){
            temp=v ;
            v=v->next ;
        }
        temp->next=v->next ;
        delete v ;
    }
}

int main(){
vector<int> arr={1 , 2 , 3 , 4 , 5} ;
create_ll(arr) ;
display_ll(head) ;
delete_element(head , 5) ;
cout<<endl ;
display_ll(head) ;
return 0 ;
}