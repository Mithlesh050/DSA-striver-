#include<bits/stdc++.h>
using namespace std ;
 
class Solution {
  private :
    bool isValidColor(int node , vector<vector<int>> &adj , vector<int> &color , int col){
        for(int i=0 ; i<adj[node].size() ; i++){
            if(color[adj[node][i]]==col) return false ;
        }
        return true ;
    }
    
    bool f(int node , vector<vector<int>> &adj , vector<int> &color , int m){
        if(node==adj.size()) return true ;
        for(int i=1 ; i<=m ; i++){
            if(isValidColor(node , adj , color , i)){
                color[node]=i ;
                if(f(node+1 , adj , color , m)) return true ;
                color[node]=0 ;
            }
        }
        return false ;
    }
    
  public:
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        vector<vector<int>> adj(v) ;
        for(int i=0 ; i<edges.size() ; i++){
            adj[edges[i][0]].push_back(edges[i][1]) ;
            adj[edges[i][1]].push_back(edges[i][0]) ;
        }
        vector<int> color(v , 0) ;
        if(f(0 , adj , color ,  m)) return true ;
        return false ;
    }
};

int main(){
Solution s ;
vector<vector<int>> edges={{0 , 1} , {1 , 3} , {2 , 3} , {3 , 0} , {0 , 2}} ;
int v=4 , m=2 ;
cout<<s.graphColoring(v , edges , m) ;
return 0 ;
}