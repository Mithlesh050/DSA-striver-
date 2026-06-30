#include<bits/stdc++.h>
using namespace std ;

class Solution {
private:
    void bfs(int row, int col, vector<vector<char>>& grid,
             vector<vector<int>>& visited) {
        visited[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for (int dr = -1; dr <= 1; dr++) {
                for (int dc = -1; dc <= 1; dc++) {
                    if(abs(dr)+abs(dc)>1) continue ;
                    int nr = i + dr, nc = j + dc;
                    if (nr >= 0 && nr < grid.size() && nc >= 0 &&
                        nc < grid[0].size() && grid[nr][nc] == '1' &&
                        visited[nr][nc] == 0) {
                        visited[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0, n = grid.size(), m = grid[0].size();
        vector < vector<int>> visited(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && visited[i][j] == 0) {
                    count++;
                    bfs(i, j, grid, visited);
                }
            }
        }
        return count;
    }
};

int main(){
vector<vector<char>> arr={{'1' , '1' , '1' , '1' , '0'} ,
                          {'1' , '1' , '0' , '1' , '0'} , 
                          {'1' , '1' , '0' , '0' , '0'} , 
                          {'0' , '0' , '0' , '0' , '0'} } ;
Solution s ;
cout<<s.numIslands(arr) ;
return 0 ;
}