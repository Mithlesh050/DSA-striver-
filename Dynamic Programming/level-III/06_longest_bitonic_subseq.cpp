#include<bits/stdc++.h>
using namespace std ;

class Solution {
  private :
    void f1(vector<int> &arr , vector<int> &dp){
        int n=arr.size() ;
        for(int i=1 ; i<n ; i++){
            for(int j=0 ; j<i ; j++){
                if(arr[i]>arr[j] && dp[i]<dp[j]+1)
                dp[i]=1+dp[j] ;
            }
        }
    }
    void f2(vector<int> &arr , vector<int> &dp){
        int n=arr.size() ;
        for(int i=n-1 ; i>=0 ; i--){
            for(int j=n-1 ; j>i ; j--){
                if(arr[i]>arr[j] && dp[i]<dp[j]+1)
                dp[i]=1+dp[j] ;
            }
        }
    }
  public:
    int longestBitonicSequence(int n, vector<int> &nums) {
        vector<int> dp1(n , 1) , dp2(n , 1) ;
        f1(nums , dp1) ;
        f2(nums , dp2) ;
        int ans=0 ;
        for(int i=0 ; i<n ; i++){
            if (dp1[i] > 1 && dp2[i] > 1) {
               int temp=dp1[i]+dp2[i]-1 ;
               if(temp>ans) ans=temp ;
            }
        }
      return ans ;  
    }
};


int main(){
Solution s ;
vector<int> nums={1, 2, 5, 3, 2} ;
int n=5 ;
cout<<s.longestBitonicSequence(n , nums) ;
return 0 ;
}