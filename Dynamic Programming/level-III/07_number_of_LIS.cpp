#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int maxi=1 , ans=0 , n=nums.size() ;
        vector<int> dp(n , 1) , count(n , 1) ;
        for(int i=1 ; i<n ; i++){
            for(int j=0 ; j<i ; j++){
                if(nums[i]>nums[j]){
                    if(dp[i]<dp[j]+1){
                       dp[i]=1+dp[j] ;
                       count[i]=count[j] ;
                    }
                    else if(dp[i]==dp[j]+1)
                        count[i]+=count[j] ;
                }
            }
            maxi=max(maxi , dp[i]) ;
        }
        for(int i=0 ; i<n ; i++){
            if(dp[i]==maxi) ans+=count[i] ;
        }
        return ans ;
    }
};

int main(){
Solution s ;
vector<int> nums={100,90,80,70,60,50,60,70,80,90,100} ;
cout<<s.findNumberOfLIS(nums) ;
return 0 ;
}