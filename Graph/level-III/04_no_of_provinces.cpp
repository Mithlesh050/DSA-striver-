#include<bits/stdc++.h>
using namespace std ;

class disjointSet{
    public:
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
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size() , ans=0;
        disjointSet ds(n) ;
        for(int i=0 ; i<n ; i++){
            for(int j=i+1 ; j<n ; j++){
               if(isConnected[i][j]==1) ds.unionBysize(i , j) ;
            }
        }
        for(int i=0 ; i<n ; i++){
            if(ds.parent[i]==i) ans++ ;
        }
        return ans ;
    }
};

int main(){
Solution s ;
vector<vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
cout << s.findCircleNum(isConnected);
return 0 ;
}