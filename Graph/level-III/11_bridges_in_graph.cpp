#include<bits/stdc++.h>
using namespace std ;

class Solution {
    int timer = 0;

private:
    void dfs(int node, int parent, vector<vector<int>>& adj,
             vector<int>& timeIn, vector<int>& low, vector<int>& visited,
             vector<vector<int>>& ans) {
                visited[node]=1 ;
                timeIn[node]=low[node]=timer ;
                timer++ ;
                for(auto it : adj[node]){
                    if(it==parent) continue ;
                    if(visited[it]==0){
                        dfs(it , node , adj , timeIn , low , visited , ans) ;
                        low[node]=min(low[node] , low[it]) ;
                        if(low[it]>timeIn[node]){
                            ans.push_back({it,node}) ;
                        }
                    }
                    else{
                        low[node]=min(low[node] , low[it]) ;
                    }
                }
             }

public:
    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>>& connections) {
        vector<vector<int>> adj(n) ;
        for(int i=0 ; i<connections.size() ; i++){
            adj[connections[i][0]].push_back(connections[i][1]) ;
            adj[connections[i][1]].push_back(connections[i][0]) ;
        }
        vector<int> timeIn(n);
        vector<int> low(n);
        vector<int> visited(n, 0);
        vector<vector<int>> ans;
        dfs(0, -1 , adj, timeIn, low, visited, ans);
        return ans ;
    }
};

int main(){
    Solution s;
    vector<vector<int>> connections = {{0, 1}, {1, 2}, {2, 0}, {1, 3}};
    int n = 4;
    vector<vector<int>> ans = s.criticalConnections(n, connections);
    for(auto it : ans){
        cout << "(" << it[0] << " , " << it[1] << ")" << " ";
    }
    return 0;
}