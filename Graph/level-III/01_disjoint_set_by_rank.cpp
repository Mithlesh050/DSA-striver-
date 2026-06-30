#include<bits/stdc++.h>
using namespace std ;

class disjointSet{
    vector<int> parent , rank ; 
    public :
    disjointSet(int n){
        rank.resize(n , 0) ;
        parent.resize(n);
        for(int i=0 ; i<=n ; i++){
            parent[i] = i;
        }
    }
    int findUparent(int node){
        if(node==parent[node])
            return node;
        return parent[node]=findUparent(parent[node]);
    }
    void unionByrank(int u , int v){
        int ultiparentU=findUparent(u) ;
        int ultiparentV = findUparent(v);
        if(ultiparentU==ultiparentV)
            return;
        else if(rank[ultiparentU]<rank[ultiparentV]){
            parent[ultiparentU] = ultiparentV;
        }
        else if(rank[ultiparentU]>rank[ultiparentV]){
            rank[ultiparentV]=ultiparentU ;
        }
        else{
           rank[ultiparentV]=ultiparentU ;
           rank[ultiparentU]++;
        }
    }
};

int main(){
    disjointSet ds(7);
    ds.unionByrank(1, 2);
    ds.unionByrank(2, 3);
    ds.unionByrank(4, 5);
    ds.unionByrank(6, 7);
    ds.unionByrank(5, 6);
    if(ds.findUparent(3)==ds.findUparent(7)) cout<<"Same" ;
    else
        cout << "Not Same";
    cout << endl;
    ds.unionByrank(3, 7);
    if(ds.findUparent(3)==ds.findUparent(7)) cout<<"Same" ;
    else
        cout << "Not Same";
    return 0;
}