#include<bits/stdc++.h>
using namespace std ;

int numEnclaves(vector<vector<int>>& grid) {
        int row=grid.size() , col=grid[0].size() ;
        vector<vector<int>> visited(row , vector<int> (col , 0)) ;
        queue<pair<int , int>> q ;
        for(int i=0 ; i<row ; i++){
            for(int j=0 ; j<col ; j++){
                if(grid[i][j]==1 && (i==0 || i==row-1 || j==0 || j==col-1)){
                    q.push({i , j}) ;
                    visited[i][j]=1 ;
                }
            }
        }
        int rowmat[]={-1 , 0 , 1 , 0} ;
        int colmat[]={0 , -1 , 0 , 1} ;
        while(!q.empty()){
            int r=q.front().first ;
            int c=q.front().second ;
            q.pop() ;
            for(int i=0 ; i<4 ; i++){
                int nr=r+rowmat[i] ;
                int nc=c+colmat[i] ;
                if(nr>=0 && nr<row && nc>=0 && nc<col && grid[nr][nc]==1 && visited[nr][nc]==0){
                    q.push({nr , nc}) ;
                    visited[nr][nc]=1 ;
                }
            }
        }
        int ans=0 ;
        for(int i=0 ; i<row ; i++){
            for(int j=0 ; j<col ; j++){
                if(grid[i][j]==1 && visited[i][j]==0)
                ans++ ;
            }
        }
        return ans ;
    }

int main(){
    vector<vector<int>> grid = {{0, 0, 0, 0},
                                {1, 0, 1, 0},
                                {0, 1, 1, 0},
                                {0, 0, 0, 0}};
    cout << numEnclaves(grid);
    return 0;
}