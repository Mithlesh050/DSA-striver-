#include<bits/stdc++.h>
using namespace std ;

class Solution {
private :
    bool f(int index , int k , vector<int> &nums , vector<vector<int>> &dp){
        if(k==0) return true ;
        if(index==0) return (nums[index]==k) ;
        if(dp[index][k]!=-1) return dp[index][k] ;
        bool notTake = f(index-1 , k , nums , dp) ;
        bool take = false ;
        if(nums[index]<=k){
            take = f(index-1 , k-nums[index] , nums , dp) ;
        }
        return dp[index][k]=(take || notTake) ;
    }
public:
    bool canPartition(vector<int>& nums) {
        int k=0 , n=nums.size();
        for(int i=0 ; i<n ; i++) k+=nums[i] ;
        if(k%2==1) return false ;
        k=k/2 ;
        vector<vector<int>> dp(n , vector<int> (k+1 , -1)) ;
        return f(n-1 , k , nums , dp) ;
    }
};

int main(){
 Solution s ;
 vector<int> nums = {1, 5, 11, 5};
 cout << s.canPartition(nums);
 return 0;
}