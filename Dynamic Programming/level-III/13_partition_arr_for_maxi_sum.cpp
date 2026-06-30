#include<bits/stdc++.h>
using namespace std ;

/* class Solution {
private :
    int f(int i , int k , vector<int> &arr , vector<int> &dp){
        if(i==arr.size()) return 0 ;
        if(dp[i]!=-1) return dp[i] ;
        int len=0 , maxAns=INT_MIN , maxi=INT_MIN ;
        for(int j=i ; j<min((int)arr.size() , i+k) ; j++){
            len++ ;
            maxi=max(maxi , arr[j]) ;
            int sum=len*maxi + f(j+1 , k , arr , dp) ;
            maxAns=max(maxAns , sum) ;
        }
        return dp[i] = maxAns ;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size() ;
        vector<int> dp(n , -1) ;
        return f(0 , k , arr , dp) ;
    }
}; */

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1 , 0);
        for (int i = n - 1; i >= 0; i--) {
            int len = 0, maxAns = INT_MIN, maxi = INT_MIN;
            for (int j = i; j < min((int)arr.size(), i + k); j++) {
                len++;
                maxi = max(maxi, arr[j]);
                int sum = len * maxi + dp[j + 1] ;
                maxAns = max(maxAns, sum);
            }
            dp[i] = maxAns;
        }
        return dp[0] ;
    }
};

int main(){
Solution s ;
vector<int> arr={1,15,7,9,2,5,10} ;
int k=3 ;
cout<<s.maxSumAfterPartitioning(arr , k) ;
return 0 ;
}