#include<bits/stdc++.h>
using namespace std ;

/* class Solution {
  private :
    int f(int ind , int target , vector<int>& arr , vector<vector<int>>&dp){
        if(ind==0){
            if(target%arr[ind]==0)  return target/arr[ind] ;
            else return 1e9 ;
        }
        if(dp[ind][target]!=-1) return dp[ind][target] ;
        int ntake = f(ind-1 , target , arr , dp) ;
        int take=INT_MAX ;
        if(arr[ind]<=target) take = 1+f(ind , target-arr[ind] , arr , dp) ;
        return dp[ind][target]=min(take , ntake) ;
    }
  public:
    int findMin(int n) {
       vector<int> arr={1 , 2 , 5 , 10} ;
       vector<vector<int>> dp(4 , vector<int>(n+1 , -1)) ;
       return f(3 , n , arr , dp) ;
    }
}; */

class Solution
{
public:
    int findMin(int n)
    {
        vector<int> arr = {1, 2, 5, 10};
        vector<vector<int> > dp(4, vector<int>(n + 1, 0));
        for (int i = 0; i <= n; i++)
        {
            if (i % arr[0] == 0)
                dp[0][i] = i / arr[0];
            else
                dp[0][i] = 1e9;
        }
        for (int ind = 1; ind < 4; ind++)
        {
            for (int target = 0; target <= n; target++)
            {
                int ntake = dp[ind - 1][target];
                int take = INT_MAX;
                if (arr[ind] <= target)
                    take = 1 + dp[ind][target - arr[ind]];
                dp[ind][target] = min(take, ntake);
            }
        }
        return dp[3][n];
    }
};

int main(){
    // coins available --> {1, 2, 5, 10};
    Solution s;
    int n = 39;
    cout << s.findMin(n);
    return 0;
}