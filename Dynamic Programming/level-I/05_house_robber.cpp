#include<bits/stdc++.h>
using namespace std ;

// iterative
/* class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(), fs, ss;
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        for (int i = 1; i < n; i++) {
            fs = nums[i];
            if (i - 2 >= 0)
                fs += dp[i - 2];
            ss = dp[i - 1];
            dp[i] = max(fs, ss);
        }
        return dp[n-1] ;
    }
}; */

// recursion
class Solution {
private :
    int f(int n , vector<int> &nums , vector<int> &dp){
        if(n==0) return nums[0] ;
        if(n<0) return 0 ;
        if(dp[n]!=-1) return dp[n] ;
        int take=nums[n]+f(n-2 , nums , dp) ;
        int notTake=f(n-1 , nums , dp) ;
        return dp[n]=max(take , notTake) ;
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size() ;
        vector<int> dp(n , -1) ;
        int ans=f(n-1 , nums , dp) ;
        return ans ;
    }
};

int main(){
vector<int> nums={1,2,3,1} ;
Solution s ;
cout << s.rob(nums);
return 0 ;
}