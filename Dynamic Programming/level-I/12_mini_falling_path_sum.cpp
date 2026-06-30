#include<bits/stdc++.h>
using namespace std ;

// TC --> O(n^2) & SC --> O(n) + O(n^2) ;
/* class Solution {
private:
    int f(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if (j < 0 || j > matrix[0].size() - 1)
            return 1e9;
        if (i == 0)
            return matrix[i][j];
        if (dp[i][j] != 1e9)
            return dp[i][j];
        int up = matrix[i][j] + f(i - 1, j, matrix, dp);
        int ld = matrix[i][j] + f(i - 1, j - 1, matrix, dp);
        int rd = matrix[i][j] + f(i - 1, j + 1, matrix, dp);
        return dp[i][j] = min(up, min(ld, rd));
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 1e9));
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            int temp = f(n - 1, i, matrix, dp);
            if (temp < ans)
                ans = temp;
        }
        return ans;
    }
}; */

// Tabulation TC --> O(n^2) 
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 1e9));
        for (int i = 0; i < n; i++)
            dp[0][i] = matrix[0][i];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int up = 1e9, ld = 1e9, rd = 1e9;
                up = matrix[i][j] + dp[i - 1][j];
                if (j > 0)
                    ld = matrix[i][j] + dp[i - 1][j - 1];
                if (j < n - 1)
                    rd = matrix[i][j] + dp[i - 1][j + 1];
                dp[i][j] = min(up, min(ld, rd));
            }
        }
        int ans=1e9 ;
        for(int i=0 ; i<n ; i++){
            if(dp[n-1][i]<ans) ans=dp[n-1][i] ;
        }
        return ans ;
    }
};

int main(){
    Solution s;
    vector<vector<int>> matrix ={{2,1,3},{6,5,4},{7,8,9}} ;
    cout << s.minFallingPathSum(matrix);
    return 0;
}