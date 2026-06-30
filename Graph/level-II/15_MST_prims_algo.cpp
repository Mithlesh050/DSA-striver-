#include<bits/stdc++.h>
using namespace std ;

int spanningTree(int V, vector<vector<int>>& edges) {
        int minCost=0 ;
        vector<vector<pair<int , int>>> adj(V) ;
        for(int i=0 ; i<edges.size() ; i++){
            adj[edges[i][0]].push_back({edges[i][2] , edges[i][1]}) ;
            adj[edges[i][1]].push_back({edges[i][2] , edges[i][0]}) ;
        }
        priority_queue<pair<int , pair<int , int>> , vector<pair<int , pair<int , int>>> , greater<pair<int , pair<int , int>>>> pq ;
        vector<int> visited(V , 0) ;
        pq.push({0 , {0 , 0}}) ;
        while(!pq.empty()){
            int dist=pq.top().first ;
            int node=pq.top().second.first ;
            int parent=pq.top().second.second ;
            if(visited[node]==0) 
            minCost+=dist ;
            visited[node]=1 ;
            pq.pop() ;
            for(auto it : adj[node]){
                if(visited[it.second]==0){
                    pq.push({it.first , {it.second , node}}) ;
                }
            }
        }
        return minCost ;
    }


int main(){
    vector<vector<int>> edges = {{0, 1, 5}, {1, 2, 3}, {0, 2, 1}};
    int V = 3;
    cout << spanningTree(V, edges);
    return 0;
}