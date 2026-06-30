#include<bits/stdc++.h>
using namespace std ;
 
class Solution {
  private :
  void fun(int node , vector<vector<int>> &adj , int visited[] , vector<int> &ans){
      visited[node]=1 ;
      ans.push_back(node) ;
      for(auto it : adj[node]){
          if(visited[it]!=1){
              fun(it , adj , visited , ans) ;
          }
      }
  }
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        vector<int> ans ;
        int n=adj.size() ;
        int visited[n]={0} ;
       fun(0 , adj , visited , ans) ;
       return ans ;
    }
};
int main(){
vector<vector<int>> adj={{2 , 3 , 1} , {0} , {0 , 4} , {0} , {2}} ;
Solution s ;
vector<int> ans=s.dfs(adj) ;
for(auto it : ans) cout<<it<<" " ;
return 0 ;
}