#include<bits/stdc++.h>
using namespace std ;

// TC --> O(n) && SC --> O(2n)
/* class Solution {
  private :
    int cal(int n, vector<int>& stones, vector<int>& dp) {
        int left, right=INT_MAX;
        if (n == 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];
        left = cal(n - 1, stones, dp) + abs(stones[n] - stones[n - 1]);
        if (n > 1)
            right = cal(n - 2, stones, dp) + abs(stones[n] - stones[n - 2]);
        return dp[n] = min(left, right);
    }
  public:
    int minCost(vector<int>& height) {
       int n=height.size() ;
       vector<int> dp(n+1 , -1) ;
       int ans=cal(n-1 , height , dp) ;
       return ans ;
    }
}; */

// iterative 
class Solution{
    public :
    int minCost (vector<int> &height){
        int n = height.size();
        int prev1 = 0, prev2 = 0, curr, ss , fs;
        for(int i=1 ; i<n ; i++){
            fs = prev1 + abs(height[i]-height[i-1]);
            if(i>1)
                ss = prev2 + abs(height[i]-height[i-2]);
            prev1 = prev2;
            prev2 = curr;
            curr = min(fs, ss);
        }
        return prev2;
    }
};

int main(){
    Solution s;
    vector<int> height = {20, 30, 40, 20};
    cout << s.minCost(height);
    return 0;
}