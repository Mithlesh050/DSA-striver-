#include<bits/stdc++.h>
using namespace std ;
struct Node{
     int key ;
     Node *next ;
     Node(int x) : key(x) , next(NULL){} ;
}*head;
 
void create_ll(vector<int> &arr){
      struct Node * temp , *last ;
        head=new Node(arr[0]) ;
        last=head ;
        for(int i=1 ; i<arr.size() ; i++){
            temp=new Node(arr[i]) ;
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

Node *rotate_list(Node *head , int k){
      Node *temp=head ;
      int count=1 ;
      while(temp->next){
        count++ ;
        temp=temp->next ;
      }
      temp->next=head ;
      temp=head ;
      k=count-k%count-1 ;
      while(k){
        temp=temp->next ;
        k-- ;
      }
      head=temp->next ;
      temp->next=NULL ;
      return head ;
}

int main(){
vector<int> arr={1 , 2 , 3 , 4 , 5 , 6 } ;
create_ll(arr) ;
display(head) ;
cout<<endl ;
int k=2 ;
Node *ans=rotate_list(head , k) ;
display(ans) ;
return 0 ;
}