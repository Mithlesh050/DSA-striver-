#include<bits/stdc++.h>
using namespace std ;

/* class Solution {
private :
    int f(int ind , int buy , vector<int> &prices , vector<vector<int>> &dp){
        if(ind==prices.size()) return 0 ;
        int profit=0 ;
        if(dp[ind][buy]!=-1) return dp[ind][buy] ;
        if(buy)
            profit = max(-prices[ind]+f(ind+1 , !buy , prices , dp) , f(ind+1 , buy , prices , dp)) ;
        else{
            profit = max(prices[ind]+f(ind+1 , !buy , prices , dp) , f(ind+1 , buy , prices , dp)) ;
        }
        return dp[ind][buy]=profit ;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size() ;
        vector<vector<int>> dp(n , vector<int>(2 , -1)) ;
        return f(0 , 1 , prices , dp) ;
    }
};
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size() ;
        vector<vector<int>> dp(n+1 , vector<int>(2 , 0)) ;
        for(int ind=n-1 ; ind>=0 ; ind--){
            for(int buy=0 ; buy<2 ; buy++){
                int profit=0 ;
                if(buy) 
                profit = max(-prices[ind]+dp[ind+1][!buy] , dp[ind+1][buy]) ;
                else{
                profit = max(prices[ind]+dp[ind+1][!buy] , dp[ind+1][buy]) ;  
                }
                dp[ind][buy]=profit ;
            }
        }
        return dp[0][1] ;
    }
};

int main(){
Solution s ;
vector<int> prices={7,1,5,3,6,4} ;
cout << s.maxProfit(prices);
return 0 ;
}