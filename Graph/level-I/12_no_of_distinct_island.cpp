#include<bits/stdc++.h>
using namespace std ;

class Solution {
	private:
	void bfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &visited, set<vector<vector<int>>> &st) {
	    vector<vector<int>> arr ;
	    arr.push_back({0 , 0}) ;
		visited[row][col]=1 ;
		queue<pair<int , int>> q ;
		q.push({row , col}) ;
		int rowmat[]={-1 , 0 , 1 , 0} ;
		int colmat[]={0 , -1 , 0 , 1} ;
		while(!q.empty()){
		    int r=q.front().first ;
		    int c=q.front().second ;
		    q.pop() ;
		    for(int i=0 ; i<4 ; i++){
		        int nr=r+rowmat[i] ;
		        int nc=c+colmat[i] ;
		        if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && grid[nr][nc]==1 && visited[nr][nc]==0){
		           q.push({nr , nc}) ;
		           visited[nr][nc]=1 ;
		           arr.push_back({nr-row , nc-col}) ;
		        }
		    }
		}
		st.insert(arr) ;
	}
	public:
	int countDistinctIslands(vector<vector<int>> & grid) {
		int row = grid.size(), col = grid[0].size() ;
		set<vector<vector<int>>> st ;
		vector<vector<int>> visited(row, vector<int> (col, 0)) ;
		for (int i = 0 ; i<row ; i++) {
			for (int j = 0 ; j<col ; j++) {
				if (grid[i][j] == 1 && visited[i][j] == 0) {
					bfs(i, j, grid, visited, st) ;
				}
			}
		}
		return st.size() ;
	}
};

int main(){
    Solution s;
    vector<vector<int>> grid = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0},
    };
    cout << s.countDistinctIslands(grid);
    return 0;
}