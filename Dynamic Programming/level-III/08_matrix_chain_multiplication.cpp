#include<bits/stdc++.h>
using namespace std ;

// TC --> O(n^3) && SC --> O(n^2 + n) ;
/* class Solution {
  private :
    int f(int i , int j , vector<int> &arr , vector<vector<int>> &dp){
        if(i==j) return 0 ;
        if(dp[i][j]!=-1) return dp[i][j] ;
        int mini=INT_MAX ;
        for(int k=i ; k<j ; k++){
            int steps=arr[i-1]*arr[k]*arr[j] + f(i , k , arr , dp) + f(k+1 , j , arr , dp) ;
            mini=min(mini , steps) ;
        }
        return dp[i][j]=mini ;
    }
  public:
    int matrixMultiplication(vector<int> &arr) {
        int n=arr.size() ;
        int i=1 , j=n-1 ;
        vector<vector<int>> dp(n , vector<int>(n , -1)) ;
        return f(i , j , arr , dp) ;
    }
}; */

// Tabulation
class Solution {
	public:
	int matrixMultiplication(vector<int> &arr) {
		int n = arr.size() ;
		vector<vector<int>> dp(n, vector<int>(n, 0)) ;
		for (int i = n - 1 ; i >= 1 ; i--) {
			for (int j = i + 1 ; j<n ; j++) {
				int mini = INT_MAX ;
				for (int k = i ; k<j ; k++) {
					int steps = arr[i - 1]*arr[k]*arr[j] + dp[i][k] + dp[k + 1][j] ;
					mini = min(mini, steps) ;
				}
				dp[i][j] = mini ;
			}
		}
	    return dp[1][n-1] ;
	}
};


int main(){
Solution s ;
vector<int> arr={2, 1, 3, 4} ;
cout<<s.matrixMultiplication(arr) ;
return 0 ;
}