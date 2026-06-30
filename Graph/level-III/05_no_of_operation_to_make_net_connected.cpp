#include<bits/stdc++.h>
using namespace std ;
 
class disjointSet{
    public :
    vector<int> size , parent ;
    disjointSet(int n){
        size.resize(n , 1) ;
        parent.resize(n) ;
        for(int i=0 ; i<n ; i++){
            parent[i]=i ;
        }
    }
    int findUparent(int node){
        if(node==parent[node]) return node ;
        return parent[node]=findUparent(parent[node]) ;
    }
    void unionBysize(int u , int v){
        int upu=findUparent(u) ;
        int upv=findUparent(v) ;
        if(upu==upv) return ;
        else if(size[upu]<size[upv]){
            parent[upu]=upv ;
            size[upv]+=size[upu] ;
        }
        else{
            parent[upv]=upu ;
            size[upu]+=size[upv] ; 
        }
    }
} ;

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int ans=-1 , extra=0;
        disjointSet ds(n) ;
        for(int i=0 ; i<connections.size() ; i++){
            int u=connections[i][0] ;
            int v=connections[i][1] ;
            if(ds.findUparent(u)==ds.findUparent(v)) extra++ ;
            else
            ds.unionBysize(u , v) ;
        }
        int cc=0 ;
        for(int i=0 ; i<n ; i++){
            if(ds.parent[i]==i) cc++ ;
        }
        if(cc-1<=extra) ans=cc-1 ;
        return ans ;
    }
};

int main() {
    vector<vector<int>> connections = {{0, 1},{0, 2},{0, 3},{1, 2}, {1, 3}};
    int n = 6;
    Solution s;
    cout << s.makeConnected(n, connections);
    return 0;
}