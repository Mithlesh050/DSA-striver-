#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size() ;
        vector<int> next(2 , 0) , curr(2 , 0) ;
        for(int ind=n-1 ; ind>=0 ; ind--){
            for(int buy=0 ; buy<2 ; buy++){
                int profit=0 ;
                if(buy) 
                profit = max(-prices[ind]+next[!buy] , next[buy]) ;
                else{
                profit = max(prices[ind]+next[!buy]-fee , next[buy]) ;  
                }
                curr[buy]=profit ;
            }
            next=curr ;
        }
        return next[1] ;
    }
};

int main(){
Solution s ;
vector<int> prices={7,1,5,3,6,4} ;
int fee = 3;
cout << s.maxProfit(prices , fee);
return 0 ;
}