#include<bits/stdc++.h>
using namespace std ;

/* class Solution {
private :
    int f(int i , int j , vector<int> &nums , vector<vector<int>> &dp){
        if(i>j) return 0 ;
        if(dp[i][j]!=-1) return dp[i][j] ;
        int maxi=INT_MIN ;
        for(int ind=i ; ind<=j ; ind++){
            int costs = nums[i-1]*nums[ind]*nums[j+1] + f(i , ind-1 , nums , dp)+f(ind+1 , j , nums , dp) ;
            maxi=max(maxi , costs) ;
        }
        return dp[i][j]=maxi ;
    }
public:
    int maxCoins(vector<int>& nums) {
        int m=nums.size() ;
        nums.push_back(1) ;
        nums.insert(nums.begin() , 1) ;
        vector<vector<int>> dp(m+1 , vector<int>(m+1 , -1)) ;
        return f(1 , m , nums , dp) ;
    }
}; */

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int m = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>> dp(m + 2, vector<int>(m + 2, 0));
        for (int i = m; i >= 1; i--) {
            for (int j = i ; j <= m; j++) {
                int maxi = INT_MIN;
                for (int ind = i; ind <= j; ind++) {
                    int costs = nums[i - 1] * nums[ind] * nums[j + 1] +
                                dp[i][ind - 1] +
                                dp[ind + 1][j] ;
                    maxi = max(maxi, costs);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[1][m] ;
    }
};

int main(){
Solution s ;
vector<int> nums={3,1,5,8} ;
cout<<s.maxCoins(nums) ;
return 0 ;
}