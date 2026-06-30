#include<bits/stdc++.h>
using namespace std ;

    int orangesRotting(vector<vector<int>>& grid) {
        int ans=0 ;
        vector<vector<int>> mat=grid ;
        queue<pair<pair<int , int> , int>> q ;
        int row=grid.size() , col=grid[0].size() ;
        for(int i=0 ; i<row ; i++){
            for(int j=0 ; j<col ; j++){
                if(grid[i][j]==2)
                q.push({{i , j} , 0}) ;
            }
        }
        int rowmat[]={-1 , 0 , 1 , 0} ;
        int colmat[]={0 , 1 , 0 , -1} ;
        while(!q.empty()){
            int r=q.front().first.first ;
            int c=q.front().first.second ;
            int t=q.front().second ;
            ans=max(ans , t) ;
            q.pop() ;
            for(int i=0 ; i<4 ; i++){
               int nr=r+rowmat[i] ;
               int nc=c+colmat[i] ;
               if(nr>=0 && nr<row && nc>=0 && nc<col && grid[nr][nc]==1 && mat[nr][nc]!=2){
                 q.push({{nr , nc} , t+1}) ;
                 mat[nr][nc]=2 ;
               }
            }
        }
        for(int i=0 ; i<row ; i++){
            for(int j=0 ; j<col ; j++){
                if(mat[i][j]==1) return -1 ;
            }
        }
        return ans ;
    }

int main(){
vector<vector<int>> grid={{2 , 1 , 1} , 
                          {1 , 1 , 0} , 
                          {0 , 1 , 1} };
cout << orangesRotting(grid);
return 0 ;
}