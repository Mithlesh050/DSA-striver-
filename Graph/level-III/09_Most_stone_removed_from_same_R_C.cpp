#include<bits/stdc++.h>
using namespace std ;

class disjointSet{
    vector<int> parent , size ; 
    public :
    disjointSet(int n){
        size.resize(n , 1) ;
        parent.resize(n);
        for(int i=0 ; i<n ; i++){
            parent[i] = i;
        }
    }
    int findUparent(int node){
        if(node==parent[node])
            return node;
        return parent[node]=findUparent(parent[node]);
    }
    void unionBysize(int u , int v){
        int ultiparentU=findUparent(u) ;
        int ultiparentV = findUparent(v);
        if(ultiparentU==ultiparentV)
            return;
        else if(size[ultiparentU]<size[ultiparentV]){
            parent[ultiparentU] = ultiparentV;
            size[ultiparentV] += size[ultiparentU];
        }
        else{
           parent[ultiparentV] = ultiparentU;
            size[ultiparentU] += size[ultiparentV];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxrow=0 , maxcol=0 ;
        for(auto it : stones){
            maxrow=max(maxrow , it[0]) ;
            maxcol=max(maxcol , it[1]) ;
        }
        disjointSet ds(maxrow+maxcol+2) ;
        unordered_map<int , int> stoneNodes ;
        for(auto it : stones){
            int noderow=it[0] ;
            int nodecol=it[1]+maxrow+1 ;
            ds.unionBysize(noderow , nodecol) ;
            stoneNodes[noderow]=1 ;
            stoneNodes[nodecol]=1 ;
        }
        int count=0 ;
        for(auto it : stoneNodes){
            if(ds.findUparent(it.first)==it.first) count++ ;
        }
        return stones.size()-count ;
    }
};

int main(){
    vector<vector<int>> stones = {{0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}};
    Solution s ;
    cout << s.removeStones(stones);
    return 0;
}