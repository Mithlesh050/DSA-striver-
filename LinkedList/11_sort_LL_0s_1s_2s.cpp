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

// TC --> O(n)  && SC --> O(1) ;
Node * sort_0s_1s_2s(Node *head){
    if(head==NULL || head->next==NULL) return head ;
    Node zeroDummy(-1); 
    Node oneDummy(-1);
    Node twoDummy(-1);
    Node* zero = &zeroDummy;
    Node* one = &oneDummy;
    Node* two = &twoDummy;
    
    Node* curr = head;

    while (curr) {
        if (curr->key == 0) {
            zero->next = curr;
            zero = zero->next;
        } else if (curr->key == 1) {
            one->next = curr;
            one = one->next;
        } else {
            two->next = curr;
            two = two->next;
        }
        curr = curr->next;
    }

    zero->next = (oneDummy.next) ? oneDummy.next : twoDummy.next;
    one->next = twoDummy.next;
    two->next = NULL;
    Node * newhead=zeroDummy.next ;
    return newhead;
}

int main(){
vector<int> arr={1 , 0 , 1 , 2 , 0 , 2 , 1} ;
create_ll(arr) ;
display(head) ;
cout<<endl ;
Node *ans=sort_0s_1s_2s(head) ;
display(ans) ;
return 0 ;
}