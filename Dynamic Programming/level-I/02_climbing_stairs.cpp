#include<bits/stdc++.h>
using namespace std ;

class Solution {
private:
    int fibonacci(int n, vector<int>& dp) {
        if (n <= 1)
            return 1;
        if (dp[n] != -1)
            return dp[n];
        return dp[n] = fibonacci(n - 1, dp) + fibonacci(n - 2, dp);
    }

public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        dp[0]=1 ;
        dp[1]=1 ;
        fibonacci(n , dp) ;
        return dp[n];
    }
};

int main(){
int n=5 ;
Solution s ;
cout << s.climbStairs(n);
return 0 ;
}