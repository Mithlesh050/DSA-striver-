#include<bits/stdc++.h>
using namespace std ;

class Solution {
private :
    int f(int ind , int amount , vector<int> &coins , vector<vector<int>> &dp){
        if(ind==0){
            if(amount%coins[ind]==0) return amount/coins[ind] ;
            else return 1e9 ;
        }
        if(dp[ind][amount]!=-1) return dp[ind][amount] ;
        int npick = f(ind-1 , amount , coins , dp);
        int pick = 1e9 ;
        if(coins[ind]<=amount) pick = 1+f(ind , amount-coins[ind] , coins , dp) ;
        return dp[ind][amount]=min(pick , npick) ;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size() ;
        vector<vector<int>> dp(n , vector<int>(amount+1 , -1)) ;
        int ans = f(n-1 , amount , coins , dp) ;
        if(ans==1e9) return -1 ;
        return ans ;
    }
};

int main(){
    Solution s;
    vector<int> coins={1,2,5} ;
    int amount = 11;
    cout << s.coinChange(coins, amount);
    return 0;
}