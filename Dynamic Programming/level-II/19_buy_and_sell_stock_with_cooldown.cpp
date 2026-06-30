#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size() ;
        vector<vector<int>> dp(n+2 , vector<int>(2 , 0)) ;
        for(int ind=n-1 ; ind>=0 ; ind--){
            for(int buy=0 ; buy<2 ; buy++){
                int profit=0 ;
                if(buy) profit = max(-prices[ind]+dp[ind+1][!buy] , dp[ind+1][buy]) ;
                else{
                    profit = max(prices[ind]+dp[ind+2][!buy] , dp[ind+1][buy]) ;
                }
                dp[ind][buy]=profit ;
            }
        }
        return dp[0][1] ;
    }
};

int main(){
Solution s ;
vector<int> prices={1,2,3,0,2} ;
cout << s.maxProfit(prices);
return 0 ;
}