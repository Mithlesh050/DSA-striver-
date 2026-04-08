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

//TC --> O(n + n/2)
/*
Node *deleteMiddle(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    Node *temp = head;
    int count = 0;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    temp = head;
    if (count == 2)
    {
        temp->next = NULL;
        return head;
    }
    count = count / 2 - 1;
    while (count)
    {
        temp = temp->next;
        count--;
    }
    temp->next = temp->next->next;
    return head;
}
*/

Node *deleteMiddle(Node *head){
    if(head==NULL || head->next==NULL) return NULL ;
    if(head->next->next==NULL){head->next=NULL ; return head ;}
    Node *slow=head , *fast=head->next->next ;
    while(fast && fast->next){
        slow=slow->next ;
        fast=fast->next->next ;
    }
    Node *temp=slow->next ;
    slow->next=slow->next->next ;
    delete temp ;
    return head ;
}

int main(){
vector<int> arr={1 , 2 , 3 , 4 , 5 , 6 } ;
create_ll(arr) ;
display(head) ;
cout<<endl ;
Node *ans=deleteMiddle(head) ;
display(ans) ;
return 0 ;
}