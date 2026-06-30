#include<bits/stdc++.h>
using namespace std ;

vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        vector<vector<int>> adj(V) ;
        for(int i=0 ; i<edges.size() ; i++){
            adj[edges[i][0]].push_back(edges[i][1]) ;
            adj[edges[i][1]].push_back(edges[i][0]) ;
        }
        vector<int> visited(V , 0) ;
        vector<int> dist(V , INT_MAX) ;
        queue<pair<int , int>> q ;
        q.push({src , 0}) ;
        while(!q.empty()){
            int node=q.front().first ;
            int d=q.front().second ;
            q.pop() ;
            visited[node]=1 ;
            dist[node]=min(dist[node] , d) ;
            for(auto it : adj[node]){
                if(visited[it]==0){
                    q.push({it , d+1}) ;
                }
            }
        }
        for(int i=0 ; i<V ; i++){
            if(dist[i]==INT_MAX) dist[i]=-1 ;
        }
        return dist ;
    }

int main(){
    vector<vector<int>> edges = {{0, 1}, {0, 3}, {1, 2}, {3, 4}, {4, 5}, {2, 6}, {5, 6}, {6, 7}, {6, 8}, {7, 8}};
    int V = 9, src = 0;
    vector<int> ans = shortestPath(V, edges, src);
    for(auto it : ans)
        cout << it << " ";
    return 0;
}