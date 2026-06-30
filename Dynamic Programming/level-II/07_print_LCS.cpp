#include<bits/stdc++.h>
using namespace std ;

class Solution{
public:
    string longestCommonSubsequence(string text1, string text2) {
        int n=text1.size() , m=text2.size() ;
        vector<vector<int>> dp(n+1 , vector<int>(m+1 , 0)) ;
        for(int ind1=1 ; ind1<=n ; ind1++){
            for(int ind2=1 ; ind2<=m  ; ind2++){
               if(text1[ind1-1]==text2[ind2-1]) dp[ind1][ind2] = 1+dp[ind1-1][ind2-1];
               else dp[ind1][ind2] = max(dp[ind1-1][ind2] , dp[ind1][ind2-1]) ;  
            }
        }
        string ans = "";
        for(int i=0 ; i<dp[n][m] ; i++)
            ans += '*';
        int i = n, j = m , k=dp[n][m]-1;
        while(i>0 && j>0){
             if(text1[i-1]==text2[j-1]){
                 ans[k--] = text1[i - 1];
                 i-- ;
                 j--;
             }
             else if(dp[i][j-1]<dp[i-1][j]){
                 i--;
             }
             else
                 j--;
        }
        return ans ;
    }
};

int main(){
Solution s ;
string s1="abcde" , s2="ace" ;
cout << s.longestCommonSubsequence(s1, s2);
return 0 ;
}