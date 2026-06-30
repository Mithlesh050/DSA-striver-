#include<bits/stdc++.h>
using namespace std ;

class Solution {
private:
    int f(int n, vector<int>& nums, vector<int>& dp) {
        if (n == 0)
            return nums[0];
        if (n < 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];
        int take = nums[n] + f(n - 2, nums, dp);
        int notTake = f(n - 1, nums, dp);
        return dp[n] = max(take, notTake);
    }

public:
    int rob(vector<int>& nums) {
        int n=nums.size() ;
        if(n==1) return nums[0] ;
        vector<int> temp ;
        for(int i=1  ; i<n ; i++) temp.push_back(nums[i]) ;
        vector<int> dp(n , -1) ;
        int ans=f(n-2 , nums , dp) ;
        for(int i=0 ; i<dp.size() ; i++) dp[i]=-1 ;
        int ans1=f(n-2 , temp , dp) ;
        return max(ans , ans1) ;
    }
};

int main(){
 Solution s ;
 vector<int> nums={2 , 3 , 2} ;
 cout << s.rob(nums);
 return 0;
}