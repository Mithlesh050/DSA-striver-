#include<bits/stdc++.h>
using namespace std ;

/* class Solution {
  private :
    int f(int ind , int w , vector<int> &val , vector<int> &wt , vector<vector<int>> &dp){
        if(w==0) return 0 ;
        if(ind==0){
            if(w>=wt[ind]) return val[ind] ;
            else return 0 ;
        }
        if(dp[ind][w]!=-1) return dp[ind][w] ;
        int ntake = f(ind-1 , w , val , wt , dp) ;
        int take = INT_MIN ;
        if(wt[ind]<=w) take = val[ind]+f(ind-1 , w-wt[ind] , val , wt , dp) ;
        return dp[ind][w]=max(take , ntake) ;
    }
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
       int n=val.size() ;
       vector<vector<int>> dp(n , vector<int>(W+1 , -1)) ;
        return f(n-1 , W , val , wt , dp) ;
    }
}; */

class Solution
{
public:
    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(W + 1, 0));
        for (int i = wt[0]; i <= W; i++)
            dp[0][i] = val[0];
        for (int ind = 1; ind < n; ind++)
        {
            for (int w = 0; w <= W; w++)
            {
                int ntake = dp[ind - 1][w];
                int take = INT_MIN;
                if (wt[ind] <= w)
                    take = val[ind] + dp[ind - 1][w - wt[ind]];
                dp[ind][w] = max(take, ntake);
            }
        }
        return dp[n - 1][W];
    }
};

int main(){
Solution s ;
int W = 4 ;
vector<int> val={1 , 2 , 3} ;
vector<int> wt = {4, 5, 1};
cout << s.knapsack(W, val, wt);
return 0 ;
}