#include<bits/stdc++.h>
using namespace std ;

/* class Solution {
private :
    int f(int i , int j , int n , vector<vector<int>> &triangle , vector<vector<int>> &dp){
        if(i==n-1) return triangle[n-1][j] ;
        if(dp[i][j]!=INT_MAX) return dp[i][j] ;
        int d=triangle[i][j]+f(i+1 , j , n , triangle , dp) ;
        int dg=triangle[i][j]+f(i+1 , j+1 , n , triangle , dp) ;
        return dp[i][j]=min(d , dg) ;
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size() ;
        vector<vector<int>> dp=triangle ;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<triangle[i].size() ; j++){
                dp[i][j]=INT_MAX ;
            }
        }
        return f(0 , 0 , n , triangle , dp) ;
    }
}; */

// Tabulation
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 1e9));
        for (int i = 0; i < triangle[n - 1].size(); i++)
            dp[n - 1][i] = triangle[n - 1][i];
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i; j >=0; j--) {
                int d = triangle[i][j] + dp[i + 1][j];
                int dg = triangle[i][j] + dp[i + 1][j + 1];
                dp[i][j] = min(d, dg);
            }
        }
        return dp[0][0];
    }
};

int main(){
Solution s ;
vector<vector<int>> triangle = { {2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
cout << s.minimumTotal(triangle);
return 0 ;
}