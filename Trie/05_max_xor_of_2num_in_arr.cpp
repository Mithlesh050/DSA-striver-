#include<bits/stdc++.h>
using namespace std ;

struct Node{
    Node *links[2] ;

    bool containsKey(int bit){
        return links[bit]!=NULL ;
    }
    void put(int bit , Node *node){
        links[bit]=node ;
    }
    Node *get(int bit){
        return links[bit] ;
    }

} ;

class Trie{
    private :
    Node *root ;

    public:
    Trie(){
        root=new Node() ;
    }
    void insert(int n){
        Node *node=root ;
        for(int i=31 ; i>=0 ; i--){
            int bit=(n>>i) & 1 ;
            if(!node->containsKey(bit)){
                node->put(bit , new Node()) ;
            }
            node=node->get(bit) ;
        }
    }
    int getMax(int n){
        Node *node=root ;
        int ans=0 ;
        for(int i=31 ; i>=0 ; i--){
            int bit=(n>>i) & 1 ;
            if(node->containsKey(1-bit)){
                ans=ans | (1<<i) ;
                node=node->get(1-bit) ;
            }
            else 
                node=node->get(bit) ;

        }
        return ans ;
    }

} ;

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie ;
        int ans=0 ;
        for(int i=0 ; i<nums.size() ; i++) trie.insert(nums[i]) ;
        for(int i=0 ; i<nums.size() ; i++){
            ans=max(ans , trie.getMax(nums[i])) ;
        }
        return ans ;
    }
};

int main(){
Solution s ;
vector<int> nums={3,10,5,25,2,8} ;
cout<<s.findMaximumXOR(nums) ;
return 0 ;
}