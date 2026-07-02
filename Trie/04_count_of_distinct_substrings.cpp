#include<bits/stdc++.h>
using namespace std ;

struct Node{
    Node *links[26] ;
    
    bool containsChar(char c){
        return (links[c-'a']!=NULL) ;
    }
    void put(char c , Node *node){
        links[c-'a']=node ;
    }
    Node* get(char c){
        return links[c-'a'] ;
    }
    
} ;

class Solution {
  public:
    int countSubs(string& s) {
        int ans=0 ;
        Node *root=new Node() ;
        for(int i=0 ; i<s.length() ; i++){
            Node *node=root ;
            for(int j=i ; j<s.length() ; j++){
                if(!node->containsChar(s[j])){
                    ans++ ;
                    node->put(s[j] , new Node()) ;
                }
                node=node->get(s[j]) ;
            }
        }
       return ans ; 
    }
};

int main(){
Solution s ;
string str="ababa" ;
cout<<s.countSubs(str) ;
return 0 ;
}