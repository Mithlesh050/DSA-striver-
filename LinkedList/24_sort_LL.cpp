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

Node* middle_of_LL(Node* head) {
        Node *slow = head, *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    Node* merge_lists(Node* l1, Node* l2) {
    Node *temp1 = l1, *temp2 = l2, *temp;
    Node* ans = new Node(-1);
        temp = ans;
        while (temp1 && temp2) {
            if (temp1->key <= temp2->key) {
                temp->next = temp1;
                temp = temp1;
                temp1 = temp1->next;
            } else {
                temp->next = temp2;
                temp = temp2;
                temp2 = temp2->next;
            }
        }
        if (temp1)
            temp->next = temp1;
        if (temp2)
            temp->next = temp2;
        return ans->next;
    }

    Node* sortList(Node* head) {
        if(head==NULL || head->next==NULL) return head ;
        Node *middle=middle_of_LL(head) ;
        Node *left=head , *right=middle->next ;
        middle->next=NULL ;
        left=sortList(left) ;
        right=sortList(right) ;
        return merge_lists(left , right) ;
    }

int main(){
vector<int> arr={6 , 2 , 7 , 4 , 3 , 1} ;
create_ll(arr) ;
display(head) ;
cout<<endl ;
Node *ans=sortList(head) ;
display(ans) ;
return 0 ;
}