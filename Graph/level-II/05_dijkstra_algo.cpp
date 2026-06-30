#include<bits/stdc++.h>
using namespace std ;

// TC --> elog(v)
vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int , int>>> adj(V) ;
        for(int i=0 ; i<edges.size() ; i++){
            adj[edges[i][0]].push_back({edges[i][2] , edges[i][1]}) ;
            adj[edges[i][1]].push_back({edges[i][2] , edges[i][0]}) ;
        }
        vector<int> dist(V , INT_MAX) ;
        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq ;
        pq.push({0 , src}) ;
        dist[src]=0 ;
        while(!pq.empty()){
            pair<int , int> topEle=pq.top() ;
            int node=topEle.second ;
            pq.pop() ;
            for(auto it : adj[node]){
                if(dist[it.second]>dist[node]+it.first){
                    dist[it.second]=dist[node]+it.first ;
                    pq.push({dist[it.second] , it.second}) ;
                }
            }
        }
        return dist ;
    }

int main(){
    int V = 3 , src = 2;
    vector<vector<int>> edges = {{0, 1, 1}, {1, 2, 3}, {0, 2, 6}} ;
    vector<int> ans = dijkstra(V, edges, src);
    for(auto it : ans)
        cout << it << " ";
    return 0;
}