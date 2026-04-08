#include<bits/stdc++.h>
using namespace std ;

  struct ListNode {
      int val;
      ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

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

ListNode *merge_lists(ListNode *l1 , ListNode *l2){
       ListNode *temp1=l1 , *temp2=l2  , *temp;
       ListNode *ans= new ListNode(-1) ;
       temp=ans ;
       while(temp1 && temp2){
          if(temp1->val<=temp2->val){
            temp->next=temp1 ;
            temp=temp1 ;
            temp1=temp1->next ;
          }
          else{
            temp->next=temp2 ;
            temp=temp2 ;
            temp2=temp2->next ;
          }
       }
       if(temp1) temp->next=temp1 ;
       if(temp2) temp->next=temp2 ;
       return ans->next ;
}

int main(){
vector<int> arr1={2 , 4 , 6 , 7} ;
vector<int> arr2={1 , 3 , 5} ;
ListNode *l1 , *l2;
l1=create_ll(arr1 , l1) ;
l2=create_ll(arr2 , l2) ;
display(l1) ;
cout<<endl ;
display(l2) ;
cout<<endl ;
ListNode *ans=merge_lists(l1 , l2) ;
display(ans) ;
return 0 ;
}