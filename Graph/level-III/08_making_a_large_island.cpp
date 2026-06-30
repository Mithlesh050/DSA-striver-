#include<bits/stdc++.h>
using namespace std ;

class disjointSet {
public:
    vector<int> size, parent;
    disjointSet(int n) {
        size.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int findUparent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUparent(parent[node]);
    }
    void unionBysize(int u, int v) {
        int upu = findUparent(u);
        int upv = findUparent(v);
        if (upu == upv)
            return;
        else if (size[upu] < size[upv]) {
            parent[upu] = upv;
            size[upv] += size[upu];
        } else {
            parent[upv] = upu;
            size[upu] += size[upv];
        }
    }
} ;

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        disjointSet ds(m * n);
        int rowmat[] = {-1, 0, 1, 0};
        int colmat[] = {0, -1, 0, 1};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    int u = i * m + j;
                    for (int k = 0; k < 4; k++) {
                        int nr = i + rowmat[k];
                        int nc = j + colmat[k];
                        if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc]==1) {
                            int v = nr * m + nc;
                            ds.unionBysize(u, v);
                        }
                    }
                }
            }
        }
        int flag=0 ;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                set<pair<int, int>> st;
                if(grid[i][j]==0){
                    for(int k=0 ; k<4 ; k++){
                        int nr = i + rowmat[k];
                        int nc = j + colmat[k];
                        if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc]==1){ 
                            int upn=ds.findUparent(nr*m+nc) ;
                            st.insert({upn , ds.size[upn]}) ;
                        }                 
                    }
                    int temp=0 ;
                   for(auto it : st){
                    temp+=it.second ;
                   }
                   temp+=1 ;
                    if(ans<temp) ans=temp ;
                    flag=1 ;
                }
            }
        }
     if(flag==0) ans=ds.size[ds.parent[0]] ;
     return ans ;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{1, 1}, {1, 0}};
    cout << s.largestIsland(grid);
    return 0;
}