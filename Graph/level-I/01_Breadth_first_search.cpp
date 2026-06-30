#include<bits/stdc++.h>
using namespace std ;
 
// TC --> O(n^2) && SC --> O(3n)
vector<int> bfs(vector<vector<int>> &adj) {
        vector<int> ans ;
        int n=adj.size() ;
        int visited[n]={0} ;
        visited[0]=1 ;
        queue<int> q ;
        q.push(0) ;
        while(!q.empty()){
            int node=q.front() ;
            q.pop() ;
            ans.push_back(node) ;
            for(auto it : adj[node]){
                if(visited[it]!=1){
                q.push(it) ;
                visited[it]=1 ;  
                }
            }
        }
       return ans ; 
    }

int main(){
vector<vector<int>> adj={{2 , 3 , 1} , {0} , {0 , 4} , {0} , {2}} ;
vector<int> ans=bfs(adj) ;
for(auto it : ans) cout<<it<<" " ;
return 0 ;
}