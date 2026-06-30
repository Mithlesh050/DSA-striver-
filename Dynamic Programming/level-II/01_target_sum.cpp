#include<bits/stdc++.h>
using namespace std ;

/* class Solution
{
private:
    int f(int ind, int target, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            if (target == 0 && nums[ind] == 0)
                return 2;
            else if (target == 0 || nums[ind] == target)
                return 1;
            else
                return 0;
        }
        if (dp[ind][target] != -1)
            return dp[ind][target];
        int npick = f(ind - 1, target, nums, dp);
        int pick = 0;
        if (nums[ind] <= target)
            pick = f(ind - 1, target - nums[ind], nums, dp);
        return dp[ind][target] = pick + npick;
    }

public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int sum = 0, n = nums.size();
        for (int i = 0; i < n; i++)
            sum += nums[i];
        target = sum - target;
        if (target < 0 || target % 2 == 1)
            return 0;
        else
            target = target / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return f(n - 1, target, nums, dp);
    }
}; */

cclass Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0 , n=nums.size() ;
        for(int i=0 ;i<n ; i++) sum+=nums[i] ;
        target=sum-target ;
        if(target<0 || target%2==1) return 0 ;
        else target=target/2 ;
        vector<vector<int>> dp(n , vector<int>(target+1 , 0)) ;
        if(nums[0]==0) dp[0][0]=2 ;
        else dp[0][0]=1 ;
        if(nums[0]!=0 && nums[0]<=target) dp[0][nums[0]]=1 ;
        for(int ind=1 ; ind<n ; ind++){
            for(int t=0 ; t<=target ; t++){
                int npick = dp[ind-1][t] ;
                int pick=0 ;
                if(nums[ind]<=t) pick=dp[ind-1][t-nums[ind]] ;
                dp[ind][t]=pick+npick ;
            }
        }
        return dp[n-1][target] ;
    }
};

int main(){
Solution s ;
vector<int> nums = {1, 1, 1, 1, 1};
int target=3 ;
cout << s.findTargetSumWays(nums, target);
return 0 ;
}