#include<bits/stdc++.h>
using namespace std ;

class Solution {
    void bfs(vector<vector<int>>& mat , vector<vector<int>>& ans){
        int row=mat.size() , col=mat[0].size() ;
        vector<vector<int>> visited(row , vector<int> (col , 0)) ;
        queue<pair<pair<int , int> , int>> q ;
        for(int i=0 ; i<row ; i++){
            for(int j=0 ; j<col ; j++){
                 if(mat[i][j]==0){
                  q.push({{i , j} , 0}) ;
                  visited[i][j]=1 ;
                 }
            }
        }
        int rowmat[]={-1 , 0 , 1 , 0} ;
        int colmat[]={0 , -1 , 0 , 1} ;
        while(!q.empty()){
             int r=q.front().first.first ;
             int c=q.front().first.second ;
             int dis=q.front().second ;
             visited[r][c]=1 ;
             q.pop() ;
             for(int i=0 ; i<4 ; i++){
                int nr=r+rowmat[i] ;
                int nc=c+colmat[i] ;
                if(nr>=0 && nr<row && nc>=0 && nc<col && mat[nr][nc]==1 && visited[nr][nc]==0){
                    q.push({{nr , nc} , dis+1}) ;
                    ans[nr][nc]=dis+1 ;
                    visited[nr][nc]=1 ;
                }
             }
        }
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row=mat.size() , col=mat[0].size() ;
        vector<vector<int>> ans(row , vector<int> (col , 0)) ;
        bfs(mat , ans) ;
        return ans ;
    }
};

int main(){
    vector<vector<int>> arr = {{0, 1, 0}, {0, 1, 0}, {0, 1, 0}, {0, 1, 0}};
    Solution s;
    vector<vector<int>> ans = s.updateMatrix(arr);
    for (int i = 0; i < ans.size(); i++){
        for (int j = 0; j<ans[0].size() ;j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
        return 0;
}