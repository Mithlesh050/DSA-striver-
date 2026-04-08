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

// TC --> O(n) ;
Node *delete_kth_node(Node *head , int position){
    if(head==NULL) return head ;
    Node *slow=head , *fast=head ;
    for(int i=0 ; i<position ; i++)
     fast=fast->next ;
    if(fast==NULL){
        Node *temp=slow ;
        head=head->next ;
        delete temp ;
        return head ;
    }
    while(fast && fast->next){
        slow=slow->next ;
        fast=fast->next ;
    }
    Node *temp=slow->next ;
    slow->next=slow->next->next ;
    delete temp ;
    return head ;
}

int main(){
vector<int> arr={1 , 2 , 3 , 4 , 5} ;
create_ll(arr) ;
display(head) ;
cout<<endl ;
delete_kth_node(head , 2) ;
display(head) ;
return 0 ;
}