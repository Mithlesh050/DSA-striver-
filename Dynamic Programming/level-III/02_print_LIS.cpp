#include<bits/stdc++.h>
using namespace std ;

class Solution {
  public:
    vector<int> printLIS(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size(), maxi=1 , ind=0 ;
        vector<int> dp(n , 1) , hash(n) ;
        for (int i = 0; i < n; i++){
            hash[i]=i ;
            for (int j = 0; j < i; j++){
                if (nums[j] < nums[i] && 1 + dp[j] > dp[i]){
                    dp[i] = 1 + dp[j] ;
                    hash[i] = j;
                 }
             }
             if(dp[i]>maxi){
               maxi = dp[i] ;
               ind=i ;  
             }
        }
        while(hash[ind]!=ind){
            ans.push_back(nums[ind]) ;
            ind=hash[ind] ;
        }
        ans.push_back(nums[ind]) ;
        reverse(ans.begin() , ans.end()) ;
        return ans ;
    }
};

int main(){
Solution s ;
vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
vector<int> ans=s.printLIS(nums) ;
for(auto it : ans)
    cout << it << " ";
return 0 ;
}