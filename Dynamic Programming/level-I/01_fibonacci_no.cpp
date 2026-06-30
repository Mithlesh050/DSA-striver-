#include<bits/stdc++.h>
using namespace std ;
 
int fibonacci(int n , vector<int> &dp){
    if(n<=1)
        return n;
    if(dp[n]!=-1)
        return dp[n];
    return dp[n] = fibonacci(n - 1 , dp) + fibonacci(n - 2 , dp);
}

int main(){
int n=9 ;
vector<int> dp(n+1, -1);
dp[0] = 0;
dp[1] = 1;
fibonacci(n, dp);
cout<<"Fibonacci Series : " ;
for (int i = 0; i <= n; i++)
    cout << dp[i] << " ";
    return 0;
}