#include<bits/stdc++.h>
using namespace std ;

/* class Solution {
  private :
    int f(int day , int last , vector<vector<int>> &mat , vector<vector<int>> &dp){
        if(day==0){
            int maxi=0 ;
            for(int task=0 ; task<3 ; task++){
                if(task!=last){
                    maxi=max(maxi , mat[0][task]) ;
                }
            }
            return maxi ;
        }
        if(dp[day][last]!=-1) return dp[day][last] ;
        int maxi=0 ;
        for(int task=0 ; task<3 ; task++){
            if(task!=last){
                int point=mat[day][task] + f(day-1 , task , mat , dp) ;
                maxi=max(maxi , point) ;
            }
        }
        return dp[day][last]=maxi ;
    }
  public:
    int maximumPoints(vector<vector<int>>& mat) {
        int n=mat.size() ;
        vector<vector<int>> dp(n , vector<int>(4 , -1)) ;
        int ans=f(n-1 , 3 , mat , dp) ;
        return ans ;
    }
}; */

// iterative
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& mat) {
        int n=mat.size() ;
        vector<vector<int>> dp(n , vector<int>(4 , 0)) ;
        dp[0][0]=max(mat[0][1] , mat[0][2]) ;
        dp[0][1]=max(mat[0][0] , mat[0][2]) ;
        dp[0][2]=max(mat[0][0] , mat[0][1]) ;
        dp[0][3]=max(mat[0][1] , max(mat[0][1] , mat[0][2])) ;
        for(int day=1 ; day<n ; day++){
            for(int last=0 ; last<4 ; last++){
                dp[day][last]=0 ;
                for(int task=0 ; task<3 ; task++){
                    if(task!=last){
                        int point=mat[day][task]+dp[day-1][task] ;
                        dp[day][last]=max(dp[day][last] , point) ;
                    }
                }
            }
        }
        return dp[n-1][3] ;
    }
};

int main(){
Solution s ;
vector<vector<int>> mat = {{1, 2, 5},
                           {3, 1, 1},
                           {3, 3, 3}};

cout<< s.maximumPoints(mat);
return 0 ;
}