#include<bits/stdc++.h>
using namespace std ;

/* class Solution {
private :
    int f(int i , int j , vector<int> &cuts , vector<vector<int>> &dp){
        if(i>j) return 0 ;
        if(dp[i][j]!=-1) return dp[i][j] ;
        int mini=1e8 ;
        for(int k=i ; k<=j ; k++){
            int cost=(cuts[j+1]-cuts[i-1])+f(i , k-1 , cuts , dp)+f(k+1 , j , cuts , dp) ;
            mini=min(mini , cost) ;
        }
        return dp[i][j]=mini ;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        int i=1 , j=cuts.size() ;
        sort(cuts.begin() , cuts.end()) ;
        vector<int> temp ;
        temp.push_back(0) ;
        for(int i=0 ; i<cuts.size() ; i++) temp.push_back(cuts[i]) ;
        temp.push_back(n) ;
        vector<vector<int>> dp(j+1 , vector<int>(j+1 , -1)) ;
        return f(i , j , temp , dp) ;
    }
}; */

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        sort(cuts.begin(), cuts.end());
        cuts.push_back(n) ;
        cuts.insert(cuts.begin() , 0) ;
        vector<vector<int>> dp(m+2, vector<int>(m+2, 0));
        for (int i = m; i >= 1; i--) {
            for (int j = i ; j <= m; j++) {
                if(i>j) continue ;
                int mini = 1e8;
                for (int k = i; k <= j; k++) {
                    int cost = (cuts[j + 1] - cuts[i - 1]) +
                               dp[i][k - 1] + dp[k + 1][j] ;
                    mini = min(mini, cost);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][m] ;
    }
};

int main(){
Solution s ;
vector<int> cuts={3 , 1 , 5 , 4} ;
int n=7 ;
cout<<s.minCost(n , cuts) ;
return 0 ;
}