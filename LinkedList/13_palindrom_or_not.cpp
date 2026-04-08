#include<bits/stdc++.h>
using namespace std ;
 
struct Node{
     int key ;
     Node *next ;
     Node(int x) : key(x), next(nullptr) {}
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

Node *reverse_LL (Node *head){
    if(head==NULL || head->next==NULL) return head; 
    Node *newhead=reverse_LL(head->next) ;
    Node *front=head->next ;
    front->next=head ;
    head->next=NULL ;
    return newhead ;
}

// TC -->  O(2n) ;
bool check_palindrom(Node *head){
    Node* slow=head , *fast=head ;
    while(fast->next && fast->next->next){
        slow=slow->next ;
        fast=fast->next ;
        fast=fast->next ;
    }
    int flag=0 ;
    Node *newhead=reverse_LL(slow->next) ;
    Node *first=head , *second=newhead ;
    while(second){
        if(first->key!=second->key){
            flag=1 ;
            break;
        }
        first=first->next ;
        second=second->next ;
    }
    reverse_LL(newhead) ;
    if(flag) return false ;
    return true ;
}

int main(){
vector<int> arr={1 , 2 , 3 , 3 , 3 , 1} ;
create_ll(arr) ;
display(head) ;
cout<<endl ;
cout<<check_palindrom(head) ;
return 0 ;
}