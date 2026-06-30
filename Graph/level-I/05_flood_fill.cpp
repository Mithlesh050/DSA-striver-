#include<bits/stdc++.h>
using namespace std ;

class Solution {
private:
    void dfs(int sr, int sc, int color, vector<vector<int>>& image,
             vector<vector<int>>& ans, int row[], int col[]) {
        int temp = image[sr][sc];
        ans[sr][sc] = color;
        for (int i = 0; i < 4; i++) {
            int nr = sr + row[i];
            int nc = sc + col[i];
            if (nr >= 0 && nr < image.size() && nc >= 0 &&
                nc < image[0].size() && image[nr][nc] == temp && ans[nr][nc]!=color) {
                dfs(nr, nc, color, image, ans, row, col);
            } 
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        vector<vector<int>> ans = image;
        int row[] = {-1, 0, 1, 0};
        int col[] = {0, -1, 0, 1};
        dfs(sr, sc, color, image, ans, row, col);
        return ans;
    }
};

int main(){
    vector<vector<int>> arr = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    int sr = 1, sc = 1, color = 2;
    Solution s;
    vector<vector<int>> ans = s.floodFill(arr, sr, sc, color);
    for (int i = 0; i < ans.size(); i++){
        for (int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
        return 0;
}