#include<bits/stdc++.h>
using namespace std ;

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1) return -1 ;
        int n=grid.size() , m=grid[0].size() ;
        vector<vector<int>> dist(n , vector<int> (m , INT_MAX)) ;
        priority_queue<pair<int , pair<int , int>> , vector<pair<int , pair<int , int>>> , greater<pair<int , pair<int , int>>>> pq ;
        pq.push({1 , {0 , 0}}) ;
        dist[0][0]=1 ;
        int rowmat[]={-1 , -1 , -1 , 0 , 0 , 1 , 1 , 1} ;
        int colmat[]={-1 , 0 , 1 , -1 , 1 , -1 , 0 , 1} ;
        while(!pq.empty()){
             auto it=pq.top() ;
             int row=it.second.first ;
             int col=it.second.second ;
             int d=it.first ;
             pq.pop() ;
            for(int i=0 ; i<8 ; i++){
                int nr=row+rowmat[i] ;
                int nc=col+colmat[i] ;
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==0 && dist[nr][nc]>d+1){
                    pq.push({d+1 , {nr , nc}}) ;
                    dist[nr][nc]=d+1 ;
                }
            } 
        } 
        if(dist[n-1][m-1]==INT_MAX) return -1 ;
        return dist[n-1][m-1] ;
    }

int main(){
    vector<vector<int>> grid = {{0, 0, 0}, {1, 1, 0}, {1, 1, 0}};
    cout << shortestPathBinaryMatrix(grid);
    return 0;
}