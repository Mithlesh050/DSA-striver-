#include<bits/stdc++.h>
using namespace std ;

class Solution {
  private : 
    bool f(int ind , int sum , vector<int> &arr , vector<vector<int>> &dp){
        if(ind==arr.size()){
            if(sum==0) return true ;
            return false ;
        }
        if(dp[ind][sum]!=-1) return dp[ind][sum] ;
        bool pick=false ;
        if(arr[ind]<=sum) pick=f(ind+1 , sum-arr[ind] , arr , dp) ;
        bool npick=f(ind+1 , sum , arr , dp) ;
        return dp[ind][sum]=(pick || npick) ;
    }
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n=arr.size() ;
        vector<vector<int>> dp(n , vector<int>(sum+1 , -1)) ;
        return f(0 , sum , arr , dp) ;
    }
};

int main(){
Solution s ;
vector<int> arr={3 , 34 , 4 , 12 , 5 , 2} ;
int sum=9 ;
cout<<s.isSubsetSum(arr , sum) ;
return 0 ;
}