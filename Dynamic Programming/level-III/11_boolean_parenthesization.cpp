#include<bits/stdc++.h>
using namespace std ;

class Solution {
  private :
    int f(int i , int j , int isTrue , string &s , vector<vector<vector<int>>> & dp){
        if(i>j) return 0 ;
        if(i==j){
            if(isTrue) return s[i]=='T' ;
            else return s[i]=='F' ;
        }
        if(dp[i][j][isTrue]!=-1) return dp[i][j][isTrue] ;
        int ways=0 ;
        for(int ind=i+1 ; ind<=j-1 ; ind+=2){
            int lt = f(i , ind-1 , 1 , s , dp) ;
            int lf = f(i , ind-1 , 0 , s , dp) ;
            int rt = f(ind+1 , j , 1 , s , dp) ;
            int rf = f(ind+1 , j , 0 , s , dp) ;
            if(s[ind]=='&'){
                if(isTrue) ways = ways + (lt*rt) ;
                else ways = ways + lt*rf + lf*rf + lf*rt ;
            }
            else if(s[ind]=='|'){
                if(isTrue) ways = ways + lt*rt + lt*rf + lf*rt ;
                else ways = ways + lf*rf ;
            }
            else{
                if(isTrue) ways = ways + lt*rf + lf*rt ;
                else ways = ways + lf*rf + lt*rt ;
            }
        }
        return dp[i][j][isTrue] = ways ;
    }
  public:
    int countWays(string &s) {
        int n=s.length() ;
        vector<vector<vector<int>>> dp(n , vector<vector<int>>(n , vector<int>(2 , -1))) ;
        return f(0 , n-1 , 1 , s , dp) ;
    }
};

int main(){
Solution s ;
string str="T|T&F^T" ;
cout<<s.countWays(str) ;
return 0 ;
}