#include<bits/stdc++.h>
using namespace std ;

 vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V) ;
        vector<int> indegree(V , 0) ;
        for(int i=0 ; i<edges.size() ; i++){
            adj[edges[i][0]].push_back(edges[i][1]) ;
            indegree[edges[i][1]]++ ;
        }
        queue<int> q ;
        for(int i=0 ; i<V ; i++){
            if(indegree[i]==0) q.push(i) ;
        }
        vector<int> ans ;
        while(!q.empty()){
            int node=q.front() ;
            q.pop() ;
            ans.push_back(node) ;
            for(auto it : adj[node]){
                indegree[it]-- ;
                if(indegree[it]==0) q.push(it) ;
            }
        }
        return ans ;
    }

int main(){
vector<vector<int>> edges = {{3, 0}, {1, 0}, {2, 0}};
int v = 4;
vector<int> ans =topoSort(v, edges);
for(auto it : ans)
    cout << it << " ";
return 0 ;
}