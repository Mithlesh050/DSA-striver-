#include<bits/stdc++.h>
using namespace std ;

/* class Solution {
private :
    int f(int ind , int prevInd , vector<int> &nums , vector<vector<int>> &dp){
        if(ind==nums.size()) return 0 ;
        if(dp[ind][prevInd+1]!=-1) return dp[ind][prevInd+1] ;
        int ntake=f(ind+1 , prevInd , nums , dp) ;
        int take=INT_MIN ;
        if(prevInd==-1 || nums[ind]>nums[prevInd]) 
             take=1+f(ind+1 , ind , nums , dp) ;
        return dp[ind][prevInd+1] = max(take , ntake) ;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size() ;
        vector<vector<int>> dp(n , vector<int>(n+1 , -1)) ;
        return f(0 , -1 , nums , dp) ;
    }
}; */


// Tabulation
/* class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n + 1, 0));
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int prevInd = ind - 1; prevInd >= -1; prevInd--) {
                int ntake = dp[ind + 1][prevInd+1] ;
                int take = INT_MIN;
                if (prevInd == -1 || nums[ind] > nums[prevInd])
                    take = 1 + dp[ind + 1][ind+1] ;
                dp[ind][prevInd + 1] = max(take, ntake);
            }
        }
        return dp[0][0] ;
    }
};
 */

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size(), ans=1 ;
        vector<int> dp(n , 1) ;
        for(int i=1 ; i<n ; i++){
            for(int j=0 ; j<i ; j++){
                  if(nums[j]<nums[i]){
                    dp[i]=max(dp[i] , 1+dp[j]) ;
                  }
            }
            ans=max(ans , dp[i]) ;
        }
        return ans ;
    }
};

int main(){
Solution s ;
vector<int> nums={10,9,2,5,3,7,101,18} ;
cout << s.lengthOfLIS(nums);
return 0 ;
}