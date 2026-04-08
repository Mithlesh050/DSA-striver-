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

// TC --> O(n)
Node *middle_of_LL(Node *head){
    Node *slow=head , *fast=head ;
    while(fast && fast->next){
        slow=slow->next ;
        fast=fast->next->next ;
    }
    return slow ;
}

int main(){
vector<int> arr={1 , 2 , 3 , 4 , 5 , 6 } ;
create_ll(arr) ;
display(head) ;
cout<<endl ;
Node *ans=middle_of_LL(head) ;
display(ans) ;
return 0 ;
}