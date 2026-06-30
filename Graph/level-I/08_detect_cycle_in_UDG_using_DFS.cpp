#include<bits/stdc++.h>
using namespace std ;

class Solution {
  private : 
    bool dfs(int node , int parent , vector<vector<int>> &adj , int visited[]){
        visited[node]=1 ;
        for(auto it : adj[node]){
            if(visited[it]==0){
               if(dfs(it , node ,  adj , visited)) return true ;
            }
            else if(it!=parent) return true ;
        }
        return false ;
    }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V) ;
        for(int i=0 ; i<edges.size() ; i++){
            adj[edges[i][0]].push_back(edges[i][1]) ;
            adj[edges[i][1]].push_back(edges[i][0]) ;
        }
        int visited[V]={0} ;
        for(int i=0 ; i<V ; i++){
            if(visited[i]==0){
                if(dfs(i , -1 , adj , visited )) return true ;
            }
        }
        return false ;
    }
};

int main(){
    Solution s;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 3}};
    int vertices = 4;
    cout << s.isCycle(vertices, edges);
return 0 ;
}