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

int main(){
vector<int> arr={1 , 2 , 3 , 4 , 5} ;
create_ll(arr) ;
display(head) ;
return 0 ;
}