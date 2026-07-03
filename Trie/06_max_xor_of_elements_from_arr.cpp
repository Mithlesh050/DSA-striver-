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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n=queries.size() , m=nums.size() ;
        vector<int> ans(n , 0) ;
        sort(nums.begin() , nums.end()) ;
        vector<pair<int , pair<int , int>>> oq ;
        for(int i=0 ; i<n ; i++){
            oq.push_back({queries[i][1] , {queries[i][0] , i}}) ;
        }
        sort(oq.begin() , oq.end()) ;
        Trie trie ;
        int ind=0 ;
        for(int i=0 ; i<oq.size() ; i++){
            int mi=oq[i].first , xi=oq[i].second.first , oi=oq[i].second.second ;
            while(ind<m && nums[ind]<=mi){
                trie.insert(nums[ind]) ;
                ind++ ;
            }
            if(ind==0) ans[oi]=-1 ;
            else ans[oi]=trie.getMax(xi) ;
        }
        return ans ;
    }
};

int main(){
Solution s ;
vector<int> nums={0 , 1 , 2 , 3 , 4} ;
vector<vector<int>> queries={{3 , 1} , {1 , 3} , {5 , 6}} ;
vector<int> ans=s.maximizeXor(nums , queries) ;
for(int i=0 ; i<ans.size() ; i++) cout<<ans[i]<<" " ;
return 0 ;
}