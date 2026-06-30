#include<bits/stdc++.h>
using namespace std ;

/* class Solution {
private :
    int f(int i , int j , vector<vector<int>> &obstacleGrid , vector<vector<int>> &dp){
        if(i>=0 && j>=0 && obstacleGrid[i][j]==1) return 0 ;
        if(i==0 && j==0) return 1 ;
        if(i<0 || j<0) return 0 ;
        if(dp[i][j]!=-1) return dp[i][j] ;
        int up=f(i-1 , j , obstacleGrid , dp) ;
        int left=f(i , j-1 , obstacleGrid , dp) ;
        return dp[i][j]=up+left ;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size() , m=obstacleGrid[0].size() ;
        if(obstacleGrid[n-1][m-1]) return 0 ;
        vector<vector<int>> dp(n , vector<int>(m , -1)) ;
        return f(n-1 , m-1 , obstacleGrid , dp) ; 
    }
};
 */
// iterative
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size() , m=obstacleGrid[0].size() ;
        if(obstacleGrid[0][0] || obstacleGrid[n-1][m-1]) return 0 ;
        vector<vector<int>> dp(n , vector<int>(m , -1)) ;
        for(int i=0 ; i<n ;  i++){
            for(int j=0 ; j<m ; j++){
                if(i==0 && j==0) dp[i][j]=1 ;
                else if(obstacleGrid[i][j]==1) dp[i][j]=0 ;
                else{
                    int up=0 , left=0 ;
                    if(i>0) up=dp[i-1][j] ;
                    if(j>0) left=dp[i][j-1] ;
                    dp[i][j]=up+left ;
                }
            }
        }
        return dp[n-1][m-1] ;
    }
};

int main(){
Solution s ;
vector<vector<int>> obstacleGrid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
cout << s.uniquePathsWithObstacles(obstacleGrid);
return 0 ;
}