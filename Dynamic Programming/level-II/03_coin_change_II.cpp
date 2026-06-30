#include<bits/stdc++.h>
using namespace std ;

class Solution {
private :
    int f(int ind , int amount , vector<int> &coins , vector<vector<int>> &dp){
        if(ind==0){
            if(amount%coins[ind]==0) return 1 ;
            else return 0 ;
        }
        if(dp[ind][amount]!=-1) return dp[ind][amount] ;
        int npick=f(ind-1 , amount , coins , dp) ;
        int pick=0 ;
        if(coins[ind]<=amount) pick = f(ind , amount-coins[ind] , coins , dp) ;
        return dp[ind][amount]=pick+npick ;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size() ;
        vector<vector<int>> dp(n , vector<int>(amount+1 , -1)) ;
        return f(n-1 , amount , coins , dp) ;
    }
};

int main(){
Solution s ;
vector<int> coins={1,2,5} ;
int amount = 5;
cout << s.change(amount, coins);
return 0 ;
}