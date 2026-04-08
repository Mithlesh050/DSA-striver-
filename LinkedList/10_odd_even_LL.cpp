#include<bits/stdc++.h>
using namespace std ;

struct ListNode {
      int val;
      ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 }*head;

void create_l1(vector<int> &arr){
        ListNode * temp , *last ;
        head=new ListNode ;
        head->val=arr[0] ;
        head->next=NULL ;
        last=head ;
        for(int i=1 ; i<arr.size() ; i++){
            temp=new ListNode ;
            temp->val=arr[i] ;
            temp->next=NULL ;
            last->next=temp ;
            last=temp ;
        }
 }

void display(ListNode *p){
    while(p){
        cout<<p->val<<" " ;
        p=p->next ;
    }
 }

 // TC --> O(2n) && SC --> O(n)
 /*
 ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head ;
        ListNode *ans , *temp , *last , *p=head;
        ans=new ListNode(head->val) ;
        last=ans ;
        while(p){
            if(p) p=p->next ;
            if(p) p=p->next ;
            if(p){
            temp=new ListNode(p->val) ;
            last->next=temp ;
            last=temp ;
            }
        }
        p=head ;
        p=p->next ;
        while(p){
            temp=new ListNode(p->val) ;
            last->next=temp ;
            last=temp ;
            if(p) p=p->next ;
            if(p) p=p->next ;
        }
       return ans ;
    }
*/

ListNode* oddEvenList(ListNode* head){
    if(head==NULL || head->next==NULL) return head ;
    ListNode *odd=head , *even=head->next , *evenHead=head->next ;
    while(even && even->next){
        odd->next=even->next ;
        odd=odd->next ;
        even->next=odd->next ;
        even=even->next ;
    }
    odd->next=evenHead ;
    return head ;
}

int main(){
vector<int> arr={1 , 2 , 3 , 4 , 5} ;
create_l1(arr) ;
display(head) ;
cout<<endl ;
ListNode *ans = oddEvenList(head) ;
display(ans) ;
return 0 ;
}