#include<bits/stdc++.h>
using namespace std ;

class Solution {
  private :
   int timer=0 ;
   void dfs(int node , int parent , vector<vector<int>> &adj , vector<int> &visited , vector<int> &timeIn , vector<int> &low , vector<int> &mark){
       visited[node]=1 ;
       timeIn[node]=low[node]=timer ;
       timer++ ;
       int child=0 ;
       for(auto it : adj[node]){
           if(it==parent) continue ;
           else if(visited[it]==0){
               dfs(it , node , adj , visited , timeIn , low , mark) ;
               low[node]=min(low[node] , low[it]) ;
               if(low[it]>=timeIn[node] && parent!=-1){
                   mark[node]=1 ;
               }
               child++ ;
           }
           else{
               low[node]=min(low[node] , low[it]) ;
           }
       }
       if(child>1 && parent==-1){
           mark[node]=1 ;
       }
   }
  public:
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
       vector<vector<int>> adj(V) ;
       for(int i=0 ; i<edges.size() ; i++){
           adj[edges[i][0]].push_back(edges[i][1]) ;
           adj[edges[i][1]].push_back(edges[i][0]) ;
       }
       vector<int> visited(V , 0) ;
       vector<int> timeIn(V) ;
       vector<int> low(V) ;
       vector<int> mark(V , 0) ;
       for(int i=0 ; i<V ; i++){
           if(visited[i]==0){
               dfs(i , -1 , adj , visited , timeIn , low , mark) ;
           }
       }
       vector<int> ans ;
       for(int i=0 ; i<V ; i++){
           if(mark[i]==1) ans.push_back(i) ;
       }
       if(ans.size())
       return ans ;
       return {-1} ;
    }
};

int main(){
 Solution s ;
 vector<vector<int>> edges = {{0, 1}, {1, 4}, {4, 3}, {4, 2}, {2, 3}};
 int v=5 ;
 vector<int> ans = s.articulationPoints(v, edges);
 for(auto it : ans)
     cout << it << " ";
 return 0;
}