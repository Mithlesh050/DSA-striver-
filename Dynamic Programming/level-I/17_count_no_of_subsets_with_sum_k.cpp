#include<bits/stdc++.h>
using namespace std ;

/* class Solution {
  private :
    int f(int ind , int k , vector<int> &arr , vector<vector<int>> &dp){
        if(ind==0){
            if(k==0 && arr[ind]==0) return 2 ;
            if(k==0 || arr[ind]==k) return 1 ;
            return 0 ;
        }
        if(dp[ind][k]!=-1) return dp[ind][k] ;
        int nPick = f(ind-1 , k , arr , dp) ;
        int pick =0 ;
        if(arr[ind]<=k)
            pick=f(ind-1 , k-arr[ind] , arr , dp) ;
        return dp[ind][k]= pick + nPick ;
    }
  public:
    int countSubset(vector<int> &arr, int k) {
       int n=arr.size() ;
       vector<vector<int>> dp(n, vector<int>(k + 1, -1));
       return f(n-1 , k , arr, dp) ;
    }
}; */

//Tabulation 
class Solution {
  public:
    int countSubset(vector<int> &arr, int k) {
       int n = arr.size() ;
		vector<vector<int>> dp(n, vector<int>(k + 1, 0)) ;
		if(arr[0]==0) dp[0][0]=2 ;
    else
      dp[0][0] = 1;
    if (arr[0]!=0 && arr[0] <= k) {
            dp[0][arr[0]] = 1;
        }
		for (int index = 1 ; index<n ; index++) {
			for (int target = 0 ; target <= k ; target++) {
				int nPick = dp[index - 1][target] ;
				int pick = 0 ;
				if (target >= arr[index]) {
					pick = dp[index - 1][target-arr[index]] ;
				}
				dp[index][target] = pick + nPick ;
			}
		}
		return dp[n-1][k] ;
    }
};

int main(){
 Solution s ;
 vector<int> arr={4, 2, 3, 1, 2} ;
 int k = 4;
 cout << s.countSubset(arr, k);
 return 0;
}