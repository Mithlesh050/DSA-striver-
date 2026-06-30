#include<bits/stdc++.h>
using namespace std ;

bool check(int src , vector<vector<int>> &edges , vector<int> &visited){
        visited[src]=1 ;
        queue<pair<int , int>> q ;
        q.push({src , -1}) ;
        while(!q.empty()){
            int cn=q.front().first ;
            int parent=q.front().second ;
            q.pop() ;
            for(auto it : edges[cn]){
                if(visited[it]==0){
                    q.push({it , cn}) ;
                    visited[it]=1 ;
                }
                else if(parent!=it){
                    return true ;
                }
            }
        }
        return false ;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V) ;
        for(int i=0 ; i<edges.size() ; i++){
             adj[edges[i][0]].push_back(edges[i][1]);
             adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> visited(V , 0) ;
        for(int i=0 ; i<V ; i++){
            if(visited[i]==0){
                if(check(i , adj , visited)) return true ;
            }
        }
       return false ; 
    }

int main(){
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 3}};
    int vertices = 4;
    cout << isCycle(vertices, edges);
    return 0;
}