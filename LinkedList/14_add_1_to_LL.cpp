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

// TC --> O(3n) && SC --> O(1)
/*
Node* add_1(Node *head){
    head=reverse_LL(head) ;
    Node *p=head ;
    int carry=1 ;
    while(p){
        int sum=p->key+carry ;
        p->key=sum%10 ;
        carry=sum/10 ;
        if(carry==0) break; 
        p=p->next ;
    }
    head=reverse_LL(head) ;
    if(carry){
        Node *temp=new Node(carry) ;
        temp->next=head ;
        return temp ;
    }
    return head ;
}
*/

int addhelper(Node *temp){
    if(temp==NULL) return 1 ;
    int carry=addhelper(temp->next) ;
     int sum=temp->key+carry ;
     temp->key=sum%10 ;
     return sum/10 ;
}
//TC --> O(n) && SC --> O(1)
Node* add_1(Node *head){
    int carry=addhelper(head) ;
    if(carry){
        Node *temp=new Node(carry) ;
        temp->next=head ;
        return temp ;
    }
    return head ;
}

int main(){
vector<int> arr={1 , 2 , 9} ;
create_ll(arr) ;
display(head) ;
cout<<endl ;
Node *ans=add_1(head) ;
display(ans) ;
return 0 ;
}