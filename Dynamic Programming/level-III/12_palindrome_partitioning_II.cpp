#include<bits/stdc++.h>
using namespace std ;

/* lass Solution {
private :
    int f(int i , string &s , vector<int> &dp){
        if(i==s.size()) return 0 ;
        if(dp[i]!=-1) return dp[i] ;
        int minCosts = INT_MAX ;
        for(int j=i ; j<s.size() ; j++){
            if(isPalindrome(i , j , s)){
                int costs = 1+f(j+1 , s , dp) ;
                minCosts=min(minCosts , costs) ;
            }
        }
        return dp[i] = minCosts ;
    }
    bool isPalindrome(int i , int j , string &s){
        while(i<j){
            if(s[i]==s[j]){
                i++ ;
                j-- ;
            }
            else return false ;
        }
        return true ;
    }
public:
    int minCut(string s) {
        int n=s.size() ;
        vector<int> dp(n , -1) ;
        return f(0 , s , dp)-1 ;
    }
}; */

class Solution {
private:
    bool isPalindrome(int i, int j, string& s) {
        while (i < j) {
            if (s[i] == s[j]) {
                i++;
                j--;
            } else
                return false;
        }
        return true;
    }
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        for (int i = n - 1; i >= 0; i--) {
            int minCosts = INT_MAX;
            for (int j = i ; j < n ; j++) {
                if (isPalindrome(i, j, s)) {
                    int costs = 1 + dp[j + 1] ;
                    minCosts = min(minCosts, costs);
                }
            }
            dp[i] = minCosts;
        }
        return dp[0]-1 ;
    }
};

int main(){
Solution s ;
string str="aab" ;
cout<<s.minCut(str) ;
return 0 ;
}