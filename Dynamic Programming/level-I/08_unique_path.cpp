#include<bits/stdc++.h>
using namespace std ;

// TC --> O(m*n) && SC --> O((m-1)(n-1)+m*n)
/* class Solution {
private :
    int f(int m , int n , vector<vector<int>> &dp){
        if(m==0 && n==0) return 1 ;
        if(m<0 || n<0) return 0 ;
        if(dp[m][n]!=-1) return dp[m][n] ;
        int left=f(m-1 , n , dp) ;
        int up=f(m , n-1 , dp) ;
        return dp[m][n]=left+up ;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m , vector<int>(n , -1)) ;
        return f(m-1 , n-1 , dp) ;
    }
}; */

// iterative  TC --> O(n*m) && SC --> O(m*n) ;
/* class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m , vector<int>(n , 0)) ;
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(i==0 && j==0) dp[i][j]=1 ;
                else{
                    int up=0 , left=0 ;
                    if(i>0) up = dp[i-1][j] ;
                    if(j>0) left=dp[i][j-1] ;
                    dp[i][j]=up+left ;
                }
            }
        }
        return dp[m-1][n-1] ;
    }
}; */

// mathematical approach TC --> O(min(m , n)) ;
class Solution {
public:
    int uniquePaths(int m, int n) {
        int n1=m+n-2  , r=min(n1-n+1 , n-1) ;
        long long temp=1 ;
        for(int i=0 ; i<r ; i++){
            temp=(temp*(n1-i))/(i+1) ;
        }
        return temp ;
    }
};

int main(){
int m=3 , n=7 ;
Solution s ;
cout << s.uniquePaths(m, n);
return 0 ;
}