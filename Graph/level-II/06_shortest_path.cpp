#include<bits/stdc++.h>
using namespace std ;

vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<int> ans ;
        vector<vector<pair<int , int>>> adj(n+1) ;
        for(int i=0 ; i<m ; i++){
            adj[edges[i][0]].push_back({edges[i][2] , edges[i][1]}) ;
            adj[edges[i][1]].push_back({edges[i][2] , edges[i][0]}) ;
        }
        vector<int> parent(n+1) ;
        for(int i=0 ; i<n+1 ; i++) parent[i]=i ;
        vector<int> dist(n+1 , INT_MAX) ;
        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq ;
        pq.push({0 , 1}) ;
        dist[1]=0 ;
        while(!pq.empty()){
            int node=pq.top().second ;
            pq.pop() ;
            for(auto it : adj[node]){
                if(dist[it.second]>dist[node]+it.first){
                    dist[it.second]=dist[node]+it.first ;
                    pq.push({dist[it.second], it.second}) ;
                    parent[it.second]=node ;
                }
            }
        }
        if(dist[n]==INT_MAX) return {-1} ;
        int node=n ;
        while(parent[node]!=node){
            ans.push_back(node) ;
            node=parent[node] ;
        }
        ans.push_back(1) ;
        reverse(ans.begin() , ans.end()) ;
        return ans ;
    }

int main(){
    int n = 5, m = 6;
    vector<vector<int>> edges = {{1, 2, 2}, {2, 5, 5}, {2, 3, 4}, {1, 4, 1}, {4, 3, 3}, {3, 5, 1}};
    vector<int> ans = shortestPath(n, m, edges);
    for(auto it : ans)
        cout << it << " ";
    return 0;
}