#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size()==1) return nums ;
        sort(nums.begin(), nums.end());
        int n = nums.size(), ind=0, maxi = 1;
        vector<int> dp(n, 1), hash(n);
        for (int i = 0; i < n; i++) {
            hash[i]=i ;
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[i] < 1 + dp[j]) {
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                }
            }
            if (maxi < dp[i]) {
                maxi = dp[i];
                ind = i;
            }
        }
        vector<int> ans;
        ans.push_back(nums[ind]);
        while (hash[ind] != ind) {
            ind = hash[ind];
            ans.push_back(nums[ind]);
        }
        return ans;
    }
};

int main(){
Solution s ;
vector<int> nums={1,2,4,8} ;
vector<int> ans = s.largestDivisibleSubset(nums) ;
for(auto it : ans) cout<<it <<" " ;
return 0 ;
}