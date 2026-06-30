#include<bits/stdc++.h>
using namespace std ;

/* class Solution {
  private :
    int f(int ind , int target , vector<int> &arr , vector<vector<int>> &dp){
        if(ind==0){
            if(target==0 && arr[ind]==0) return 2 ;
            if(target==0 || arr[ind]==target) return 1 ;
            return 0 ;
        }
        if(dp[ind][target]!=-1) return dp[ind][target] ;
        int nPick = f(ind-1 , target , arr , dp) ;
        int pick =0 ;
        if(arr[ind]<=target)
            pick = f(ind-1 , target-arr[ind] ,arr , dp) ;
        return dp[ind][target]= pick+nPick ;
    }
  public:
    int countPartitions(vector<int>& arr, int diff) {
        int sum=0 , n=arr.size();
        for(int i=0 ; i<n ; i++) sum+=arr[i] ;
        int target=sum-diff ;
        if(target<0 || target%2==1) return 0 ;
        target=target/2 ;
        vector<vector<int>> dp(n , vector<int>(target+1 , -1)) ;
        return f(n-1 , target , arr , dp) ;
    }
}; */

// Tabulation
class Solution
{
public:
    int countPartitions(vector<int> &arr, int diff)
    {
        int sum = 0, n = arr.size();
        for (int i = 0; i < n; i++) sum += arr[i];
        int target = sum - diff;
        if (target < 0 || target % 2 == 1) return 0;
        int k = target / 2;
        vector<vector<int>> dp(n, vector<int>(k + 1, 0));
        if (arr[0] == 0)  dp[0][0] = 2;
        else  dp[0][0] = 1;
        if (arr[0] != 0 && arr[0] <= k) dp[0][arr[0]] = 1;
        for (int index = 1; index < n; index++)
        {
            for (int target = 0; target <= k; target++)
            {
                int nPick = dp[index - 1][target];
                int pick = 0;
                if (target >= arr[index])
                {
                    pick = dp[index - 1][target - arr[index]];
                }
                dp[index][target] = pick + nPick;
            }
        }
        return dp[n - 1][k];
    }
};

int main(){
Solution s;
vector<int> arr={5, 2, 6, 4} ;
int diff =3 ;
cout << s.countPartitions(arr, diff);
return 0 ;
}