#include<bits/stdc++.h>
using namespace std ;

  struct ListNode {
      int val;
      ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
 };

 // TC --> O(max(l1.size , l2.size))
 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0 , sum;
        ListNode *head=new ListNode() , *temp  , *ans=head;
        while(l1 || l2){
            sum=0 ;
            if(l1) sum=sum+l1->val ;
            if(l2) sum=sum+l2->val ;
            sum+=carry ;
            carry=sum/10 ;
            sum=sum%10 ;
            temp=new ListNode(sum) ;
            head->next=temp ;
            head=temp ;
            if(l1)
            l1=l1->next ;
            if(l2)
            l2=l2->next ;
        }
        if(carry>0){
            temp=new ListNode(carry) ;
            head->next=temp ;
            head=temp ;
        }
        return ans->next ;
    }

ListNode * create_ll(vector<int> &arr , ListNode *head){
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
        return head ;
 }
 
 void display(ListNode *p){
    while(p){
        cout<<p->val<<" " ;
        p=p->next ;
    }
 }

int main(){
vector<int> arr1={2 , 4 , 3} ;
vector<int> arr2={5 , 6 , 4} ;
ListNode *l1 , *l2 ;
l1=create_ll(arr1 , l1) ;
l2=create_ll(arr2 , l2) ;
display(l1) ;
cout<<endl ;
display(l2) ;
cout<<endl ;
ListNode *ans=addTwoNumbers(l1 , l2) ;
display(ans) ;
return 0 ;
}