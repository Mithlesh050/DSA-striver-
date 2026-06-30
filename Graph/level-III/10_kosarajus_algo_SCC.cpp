#include<bits/stdc++.h>
using namespace std ;

class Solution {
  private:
   void dfs(int node , vector<vector<int>> &adj , vector<int> &visited , stack<int> &stk){
       visited[node]=1 ;
       for(auto it : adj[node]){
           if(visited[it]==0)
           dfs(it , adj , visited , stk) ;
       }
       stk.push(node) ;
   }
   void dfs_II(int node , vector<vector<int>> &adjT , vector<int> &visited){
       visited[node]=0 ;
       for(auto it : adjT[node]){
           if(visited[it]==1)
           dfs_II(it , adjT , visited) ;
       }
   }
  public:
    int kosaraju(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V) ;
        vector<vector<int>> adjT(V) ;
        for(int i=0 ; i<edges.size() ; i++){
            adj[edges[i][0]].push_back(edges[i][1]) ;
            adjT[edges[i][1]].push_back(edges[i][0]) ;
        }
       vector<int> visited(V , 0) ;
       stack<int> stk ;
       for(int i=0 ; i<V ; i++){
           if(visited[i]==0)
           dfs(i , adj , visited , stk) ;
       }
       int ans=0 ;
       while(!stk.empty()){
           int node=stk.top() ;
           stk.pop() ;
           if(visited[node]==1){
               ans++ ;
               dfs_II(node , adjT , visited) ;
           }
       }
       return ans ;
    }
};

int main(){
    Solution s;
    vector<vector<int>> edges = {{0, 2}, {0, 3}, {1, 0}, {2, 1}, {3, 4}};
    int v=5 ;
    cout << s.kosaraju(v, edges);
    return 0;
}