#include<bits/stdc++.h>
using namespace std ;

/* class Solution {
	private :
	int f(int ind, int len, vector<int> &price, vector<vector<int>> &dp) {
		if (ind == 0)
			return (len)*price[ind] ;
		if (dp[ind][len] != -1)
			return dp[ind][len] ;
		int ntake = f(ind - 1, len, price, dp) ;
		int take = INT_MIN ;
		if (ind + 1 <= len) take = price[ind] + f(ind, len - (ind + 1), price, dp) ;
		return dp[ind][len] = max(take, ntake) ;
	}
	public:
	int cutRod(vector<int> &price) {
		int n = price.size(), ans = 0;
        vector<vector<int>> dp(n, vector<int>(n + 1, -1)) ;
		return f(n - 1, n , price , dp) ;
	}
};
 */

class Solution {
	public:
	int cutRod(vector<int> &price) {
		int n = price.size() ;
		vector<vector<int>> dp(n, vector<int>(n + 1, 0)) ;
		for (int i = 0 ; i <= n ; i++) {
			dp[0][i] = price[0]*i ;
		}
		for (int ind = 1 ; ind<n ; ind++) {
			for (int len = 0 ; len <= n ; len++) {
				int ntake = dp[ind - 1][len] ;
				int take = INT_MIN ;
				if (ind + 1 <= len)
					take = price[ind] + dp[ind][len - (ind + 1)] ;
				dp[ind][len] = max(take, ntake) ;
			}
		}
		return dp[n-1][n] ;
	}
};


int main(){
vector<int> price ={1, 5, 8, 9, 10, 17, 17, 20} ;
Solution s ;
cout << s.cutRod(price);
return 0 ;
}