#include<bits/stdc++.h>
using namespace std ;

// TC --> O(index*target)
/* class Solution {
  private :
    bool f(int index , int k , vector<int> &arr , vector<vector<int>> &dp){
        if(k==0) return true ;
        if(index==0) return (arr[index]==k) ;
        if(dp[index][k]!=-1) return dp[index][k] ;
        bool notTake=f(index-1 , k , arr , dp) ;
        bool take=false ;
        if(k>=arr[index]){
            take=f(index-1 , k-arr[index] , arr , dp) ;
        }
        return dp[index][k]=(take || notTake) ;
    }
  public:
    bool checkSubsequenceSum(vector<int>& arr, int k) {
        int n=arr.size() ;
        vector<vector<int>> dp(n , vector<int>(k+1 , -1)) ;
        return f(n-1 , k , arr , dp) ;
    }
}; */

// Tabulation
class Solution {
	public:
	bool checkSubsequenceSum(vector<int>& arr, int k) {
		int n = arr.size() ;
		vector<vector<int>> dp(n, vector<int>(k + 1, 0)) ;
		for (int i = 0 ; i<n ; i++)
			dp[i][0] = 1 ;
		if (arr[0] <= k) {
            dp[0][arr[0]] = 1;
        }
		for (int index = 1 ; index<n ; index++) {
			for (int target = 1 ; target <= k ; target++) {
				bool notTake = dp[index - 1][target] ;
				bool take = false ;
				if (target >= arr[index]) {
					take = dp[index - 1][target-arr[index]] ;
				}
				dp[index][target] = (take || notTake) ;
			}
		}
		return dp[n-1][k] ;
	}
};


int main(){
Solution s ;
vector<int> arr = {10, 1, 2, 7, 6, 1, 5} ;
int n=8 ;
cout << s.checkSubsequenceSum(arr, n);
return 0 ;
}