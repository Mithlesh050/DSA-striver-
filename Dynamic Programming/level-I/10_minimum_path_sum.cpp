#include<bits/stdc++.h>
using namespace std ;

/* class Solution {
private :
    int f(int i , int j , vector<vector<int>> &grid , vector<vector<int>> &dp){
        if(i==0  && j==0) return grid[i][j] ;
        if(i<0 || j<0) return 1e9 ;
        if(dp[i][j]!=-1) return dp[i][j] ;
        int up=grid[i][j]+f(i-1 , j , grid , dp) ;
        int left=grid[i][j]+f(i , j-1 , grid , dp) ;
        return dp[i][j]=min(up , left) ;
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size() , m=grid[0].size() ;
        vector<vector<int>> dp(n , vector<int>(m , -1)) ;
        return f(n-1 , m-1 , grid , dp) ;
    }
}; */

// Tabulation TC --> O(n*m) && SC --> O(n*m) 
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size() , m=grid[0].size() ;
        vector<vector<int>> dp(n , vector<int>(m , 0)) ;
        for(int i=0 ; i<n  ; i++){
            for(int j=0 ; j<m ; j++){
                if(i==0 && j==0) dp[i][j]=grid[i][j] ;
                else{
                    int up=INT_MAX , left=INT_MAX ;
                    if(i>0) up=grid[i][j]+dp[i-1][j] ;
                    if(j>0) left=grid[i][j]+dp[i][j-1] ;
                    dp[i][j]=min(up , left) ;
                }
            }
        }
        return dp[n-1][m-1] ;
    }
};


int main(){
Solution s ;
vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
cout << s.minPathSum(grid);
return 0 ;
}