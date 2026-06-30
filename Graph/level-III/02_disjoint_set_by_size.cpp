#include<bits/stdc++.h>
using namespace std ;

class disjointSet{
    vector<int> parent , size ; 
    public :
    disjointSet(int n){
        size.resize(n+1 , 1) ;
        parent.resize(n+1);
        for(int i=0 ; i<=n ; i++){
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


int main(){
disjointSet ds(7);
    ds.unionBysize(1, 2);
    ds.unionBysize(2, 3);
    ds.unionBysize(4, 5);
    ds.unionBysize(6, 7);
    ds.unionBysize(5, 6);
    if(ds.findUparent(3)==ds.findUparent(7)) cout<<"Same" ;
    else
        cout << "Not Same";
    cout << endl;
    ds.unionBysize(3, 7);
    if(ds.findUparent(3)==ds.findUparent(7)) cout<<"Same" ;
    else
        cout << "Not Same";
    return 0;
return 0 ;
}