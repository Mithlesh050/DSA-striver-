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

 ListNode *merge_ll(ListNode *p , ListNode *l3){
         ListNode *temp=p ;
         while(temp->next) temp=temp->next ;
         temp->next=l3 ;
         return p ;
 }

// TC --> O(nlogn) && SC --> O(l1.size)
/*
 ListNode *intersect_point(ListNode *l1 , ListNode *l2){
    map<ListNode* , int> mpp ;
    ListNode *temp=l1 ;
    while(temp){
        mpp[temp]=1 ;
        temp=temp->next ;
    }
    temp=l2 ;
    while(temp){
        if(mpp.find(temp)!=mpp.end()){
            return temp ;
        }
        temp=temp->next ;
    }
    return NULL ;
 }
*/

// TC --> O(l1.size + l2.size)
/*
ListNode *intersect_point(ListNode *l1 , ListNode *l2){
    ListNode *temp1=l1 , *temp2=l2 ;
    int n1=0 , n2=0 ;
    while(temp1){
        n1++ ;
        temp1=temp1->next ;
    }
    while(temp2){
        n2++ ;
        temp2=temp2->next ;
    }
    temp1=l1 ;
    temp2=l2 ;
    if(n1>n2){
        for(int i=0 ; i<n1-n2 ; i++) temp1=temp1->next ;
    }
    else if(n1<n2){
        for(int i=0 ; i<n2-n1 ; i++) temp2=temp2->next ;
    }
    while(temp1){
        if(temp1==temp2) return temp1 ;
        temp1=temp1->next ;
        temp2=temp2->next ;
    }
    return NULL ;
 }
*/

//optimal TC --> O(n1+n2)
ListNode *intersect_point(ListNode *l1 , ListNode *l2){
     if(l1==NULL || l2==NULL) return NULL ;
     ListNode *t1=l1 , *t2=l2 ;
     while(t1 != t2){
        t1=t1->next ;
        t2=t2->next ;
        if(t1==t2) return t1 ;
        if(t1==NULL) t1=l2 ;
        if(t2==NULL) t2=l1 ;
     }
     return t1 ;
 }


int main(){
vector<int> arr1={4 , 1} ;
vector<int> arr2={5 , 6 , 1} ;
vector<int> arr3={8 , 4 , 5} ;
ListNode *l1 , *l2  , *l3;
l1=create_ll(arr1 , l1) ;
l2=create_ll(arr2 , l2) ;
l3=create_ll(arr3 , l3) ;
l1=merge_ll(l1 , l3) ;
l2=merge_ll(l2 , l3) ;
display(l1) ;
cout<<endl ;
display(l2) ;
cout<<endl ;
ListNode *ans=intersect_point(l1 , l2) ;
display(ans) ;
return 0 ;
}