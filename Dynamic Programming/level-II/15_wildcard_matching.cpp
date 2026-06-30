#include<bits/stdc++.h>
using namespace std ;

/* class Solution {
private :
    bool f(int i , int j , string s , string p , vector<vector<int>> &dp){
        if(i<0 && j<0) return true ;
        if(i>=0 && j<0) return false ;
        if(i<0 && j>=0){
            for(int k=0 ; k<=j ; k++){
                if(p[k]!='*') return false ;
            }
            return true ;
        }
        if(dp[i][j]!=-1) return dp[i][j] ;
        if(p[j]==s[i] || p[j]=='?') return dp[i][j] = f(i-1 , j-1 , s , p , dp) ;
        else if(p[j]=='*') return dp[i][j] = (f(i-1 , j , s , p , dp) || f(i , j-1 , s , p , dp)) ;
        else return dp[i][j] = false ;
    }
public:
    bool isMatch(string s, string p) {
        int n=s.size() , m=p.size() ;
        vector<vector<int>> dp(n , vector<int>(m , -1)) ;
        return f(n-1 , m-1 , s , p , dp) ;
    }
}; */

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= m; i++) {
            if(p[i-1]=='*')
            dp[0][i] = dp[0][i-1];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                else if (p[j-1] == '*')
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                else
                    dp[i][j] = false;
            }
        }
        return dp[n][m];
    }
};

int main(){
Solution s ;
string s1 = "cb", s2 = "?a";
cout << s.isMatch(s1, s2);
return 0 ;
}