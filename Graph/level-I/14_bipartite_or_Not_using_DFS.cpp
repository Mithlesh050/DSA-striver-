#include<bits/stdc++.h>
using namespace std ;

class Solution {
private :
    bool dfs(int node ,int c , vector<vector<int>>& graph , vector<int> &color){
        color[node]=c ;
        for(auto it : graph[node]){
            if(color[it]==-1){
                if(!dfs(it , !c ,  graph , color)) return false ;
            }
            else if(color[it]==c){
                return false ;
            }
        }
        return true ;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size() ;
        vector<int> color(n , -1) ;
        for(int i=0 ; i<n ; i++){
            if(color[i]==-1){
                if(!dfs(i , 0 , graph , color)) return false ;
            }
        }
        return true ;
    }
};

int main(){
 Solution s;
    vector<vector<int>> graph = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
    bool ans = s.isBipartite(graph);
    if(ans)
        cout << "This graph is bipartite";
    else
        cout << "This graph is not bipartite";
return 0 ;
}