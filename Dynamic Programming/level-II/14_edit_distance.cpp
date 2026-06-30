#include<bits/stdc++.h>
using namespace std ;

/* class Solution {
private:
    int f(int i, int j, string s1, string s2 ,vector<vector<int>> &dp) {
        if (i < 0)
            return j+1;
        if (j < 0)
            return i+1;
        if(dp[i][j]!=-1) return dp[i][j] ;
        if (s1[i] == s2[j])
            return f(i - 1, j - 1, s1, s2 , dp);
        int insert = 1 + f(i, j - 1, s1, s2 , dp);
        int del = 1 + f(i - 1, j, s1, s2 , dp);
        int replace = 1 + f(i - 1, j - 1, s1, s2 , dp);
        return dp[i][j]= min(insert, min(del, replace));
    }

public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp (n , vector<int>(m , -1)) ;
        return f(n - 1, m - 1, word1, word2 , dp);
    }
}; */

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i <= n; i++)
            dp[i][0] = i;
        for (int i = 0; i <= m; i++)
            dp[0][i] = i;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if(word1[i-1]==word2[j-1]) dp[i][j]=dp[i-1][j-1] ;
                else{
                int insert = 1 + dp[i][j - 1] ;
                int del = 1 + dp[i - 1][j] ;
                int replace = 1 + dp[i - 1][j - 1] ;
                dp[i][j] = min(insert, min(del, replace));
                }
            }
        }
        return dp[n][m] ;
    }
};

int main(){
Solution s ;
string s1="horse" , s2="ros" ;
cout << s.minDistance(s1, s2);
return 0 ;
}