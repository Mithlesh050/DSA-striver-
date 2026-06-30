#include<bits/stdc++.h>
using namespace std ;

class Solution {
  private :
   void topo(int node , vector<vector<pair<int , int>>> &adj , vector<int> &visited , stack<int> &st ){
       visited[node]=1  ;
       for(auto it : adj[node]){
           if(visited[it.first]==0){
               topo(it.first , adj , visited , st) ;
           }
       }
       st.push(node) ;
   }
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<vector<pair<int , int>>> adj(V) ;
        for(int i=0 ; i<edges.size() ; i++){
            adj[edges[i][0]].push_back({edges[i][1] , edges[i][2]}) ;
        }
       vector<int> visited(V , 0) ;
       stack<int> st ;
       for(int i=0 ; i<V ; i++){
           if(visited[i]==0){
               topo(i , adj , visited , st) ;
           }
       }
       vector<int> dist(V , INT_MAX) ;
       dist[0]=0 ;
       while(!st.empty()){
           int node=st.top() ;
           st.pop() ;
           if (dist[node] == INT_MAX) continue;
           for(auto it : adj[node]){
               if(dist[it.first]>dist[node]+it.second){
                   dist[it.first]=dist[node]+it.second ;
               }
           }
       }
       for(int i=0 ; i<V ; i++){
           if(dist[i]==INT_MAX) dist[i]=-1 ;
       }
       return dist ;
    }
};

int main(){
    Solution s;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 4, 1}, {4, 5, 4}, {4, 2, 2}, {1, 2, 3}, {2, 3, 6}, {5, 3, 1}};
    int V = 6, E = 7;
    vector<int> ans=s.shortestPath(V , E , edges) ;
    for(auto it : ans)
        cout << it << " ";
    return 0;
}