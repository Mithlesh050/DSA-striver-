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

Node *reverse_ll(Node *head){
    if(head==NULL || head->next==NULL)
    return head ;
    Node *newhead=reverse_ll(head->next) ;
    Node *front=head->next ;
    front->next=head ;
    head->next=NULL ;
    return newhead;
}

Node *kth_node(Node *temp , int k){
    k=k-1 ;
    while(temp && k>0){
        temp=temp->next ;
        k-- ;
    }
    return temp ;
}

Node *reverse_in_k_group(Node *head , int k){
    Node *temp=head , *prevlast=NULL , *nextnode ;
    while(temp){
        Node * kthn=kth_node(temp , k);
        if(kthn==NULL){
            if(prevlast) prevlast->next=temp ;
            break; 
        }
        nextnode=kthn->next ;
        kthn->next=NULL ;
        reverse_ll(temp) ;
        if(temp==head)
          head=kthn ;
        else{
            prevlast->next=kthn ;
        } 
        prevlast=temp ;
        temp=nextnode ;
    }
    return head ;
}

int main(){
vector<int> arr={1 , 2 , 3 , 4 , 5 , 6 , 7 , 8} ;
create_ll(arr) ;
display(head) ;
cout<<endl ;
int k=4 ;
Node *ans=reverse_in_k_group(head , k) ;
display(ans) ;
return 0 ;
}