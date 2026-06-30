#include<bits/stdc++.h>
using namespace std ;

void solve(vector<vector<char>>& board) {
        int row = board.size(), col = board[0].size();
        vector<vector<int>> visited(row, vector<int>(col, 0));
        queue<pair<int, int>> q;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j]=='O' && (i == 0 || j == 0 || i == row - 1 || j == col - 1)) {
                    q.push({i, j});
                    visited[i][j] = 1;
                }
            }
        }
        int rowmat[] = {-1, 0, 1, 0};
        int colmat[] = {0, -1, 0, 1};
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nr = r + rowmat[i];
                int nc = c + colmat[i];
                if (nr >= 0 && nr < row && nc >= 0 && nc < col &&
                    board[nr][nc] == 'O' && visited[nr][nc] == 0) {
                    q.push({nr, nc});
                    visited[nr][nc] = 1;
                }
            }
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'O' && visited[i][j] == 0)
                    board[i][j] = 'X';
            }
        }
    }

int main(){
 vector<vector<char>> board={{'X' , 'X' , 'X' , 'X'} , 
                             {'X' , 'O' , 'O' , 'X'} , 
                             {'X' , 'X' , 'O' , 'X'} , 
                             {'X' , 'O' , 'X' , 'X'} } ;
solve(board);

  for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
                cout << board[i][j] << "  ";
        }
            cout << endl;
    }
 return 0;
}