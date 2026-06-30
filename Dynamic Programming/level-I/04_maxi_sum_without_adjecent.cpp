#include<bits/stdc++.h>
using namespace std ;

class Solution {
  private :
   int cal(int n , vector<int> &arr , vector<int> &dp){
        if(n==0) return arr[n] ;
        if(n<0) return 0 ;
        if(dp[n]!=-1) return dp[n] ;
        int pick = arr[n]+cal(n-2 , arr , dp) ;
        int notPick = cal(n-1 , arr , dp) ;
        return dp[n]=max(pick , notPick) ;
   }
  public:
    int findMaxSum(vector<int>& arr, int n) {
        if(n==1) return arr[0] ;
        vector<int> dp(n , -1) ;
        cal(n-1 , arr , dp) ;
        return dp[n-1] ;
    }
};

// iterative
class Solution2{
  public :
  int findMaxSum(vector<int>& arr, int n) {
        if(n==1) return arr[0] ;
        vector<int> dp(n , 0) ;
        dp[0]=arr[0] ;
        int fs , ss ;
        for(int i=1 ; i<n ; i++){
            fs=arr[i] ;
            if(i-2>=0) fs+=dp[i-2] ;
            ss=dp[i-1] ;
            dp[i]=max(fs , ss) ;
        }
        return dp[n-1] ;
    }
};

int main(){
Solution s ;
Solution2 s2 ;
vector<int> arr = {5, 5, 10, 100, 10, 5};
int n = 6;
cout << s2.findMaxSum(arr, n);
return 0 ;
}