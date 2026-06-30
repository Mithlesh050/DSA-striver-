#include<bits/stdc++.h>
using namespace std ;

/* class Solution {
private :
    int f(int i , int j , string s1 , string s2 , vector<vector<int>> &dp){
        if(i<0 || j<0) return 0 ;
        if(dp[i][j]!=-1) return dp[i][j] ;
        if(s1[i]==s2[j]) return 1 + f(i-1 , j-1 , s1 , s2 , dp) ;
        else return dp[i][j] = max(f(i-1 , j , s1 , s2 , dp) , f(i , j-1 , s1 , s2 , dp)) ;
    }
public:
    int minInsertions(string s) {
        int n=s.length() ;
        vector<vector<int>> dp(n , vector<int>(n ,  -1)) ;
        string s1=s  ;
        reverse(s.begin() , s.end()) ;
        string s2=s ;
        return n-f(n-1 , n-1 , s1 , s2 , dp) ;
    }
}; */

class Solution {
public:
    int minInsertions(string s) {
        int n=s.length() ;
        vector<int> prev(n+1 , 0) , curr(n+1 , 0) ;
        string s1=s  ;
        reverse(s.begin() , s.end()) ;
        string s2=s ;
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=n ; j++){
                if(s1[i-1]==s2[j-1]) curr[j]=1+prev[j-1] ;
                else curr[j]=max(prev[j] , curr[j-1]) ;
            }
            prev=curr ;
        }
        return n-prev[n] ;
    }
};

int main(){
 Solution s ;
 string str="mbadm" ;
 cout << s.minInsertions(str);
 return 0;
}