#include<bits/stdc++.h>
using namespace std ;

// TC --> O(n *2*3) and SC --> O(n*2*3 + n) ;
/* class Solution {
private :
    int f(int ind , int buy , int cap , vector<int> &prices , vector<vector<vector<int>>> &dp){
        if(cap==0) return 0 ;
        if(ind==prices.size()) return 0 ;
        int profit=0 ;
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap] ;
        if(buy) 
            profit=max(-prices[ind]+f(ind+1 , !buy , cap , prices , dp) , f(ind+1 , buy , cap , prices , dp)) ;
        else 
            profit=max(prices[ind]+f(ind+1 , !buy , cap-1 , prices , dp) , f(ind+1 , buy , cap , prices , dp)) ;
        return dp[ind][buy][cap] = profit ;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size() ;
        vector<vector<vector<int>>> dp(n , vector<vector<int>>(2 , vector<int>(3 , -1)) ) ;
        return f(0 , 1 , 2 , prices , dp) ;
    }
}; */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy < 2; buy++) {
                for (int cap = 1; cap < 3; cap++) {
                    int profit=0 ;
                    if (buy)
                        profit = max(-prices[ind] + dp[ind+1][!buy][cap] , dp[ind+1][buy][cap]);
                    else
                        profit = max(prices[ind] + dp[ind+1][!buy][cap-1] , dp[ind+1][buy][cap]);
                    dp[ind][buy][cap] = profit;
                }
            }
        }
        return dp[0][1][2] ;
    }
};

int main(){
Solution s;
vector<int> prices = {3,3,5,0,0,3,1,4} ;
cout << s.maxProfit(prices);
return 0 ;
}