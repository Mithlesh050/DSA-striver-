#include<bits/stdc++.h>
using namespace std ;

// User function Template for C++
class disjointSet {
	vector<int> size, parent ;
	public :
	disjointSet(int n) {
		size.resize(n, 1) ;
		parent.resize(n) ;
		for (int i = 0 ; i<n ; i++) {
			parent[i] = i ;
		}
	}
	int findUparent(int node) {
		if (node == parent[node])
			return node ;
		return parent[node] = findUparent(parent[node]) ;
	}
	void unionBysize(int u, int v) {
		int upu = findUparent(u) ;
		int upv = findUparent(v) ;
		if (upu == upv)
			return ;
		else if (size[upu]<size[upv]) {
			parent[upu] = upv ;
			size[upv] += size[upu] ;
		}
		else {
			parent[upv] = upu ;
			size[upu] += size[upv] ;
		}
	}
};

class Solution {
	public:
	vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
		vector<int> ans ;
		disjointSet ds(n*m) ;
		vector<vector<int>> visited(n, vector<int>(m, 0)) ;
		int rowmat[] = {-1, 0, 1, 0} ;
		int colmat[] = {0, -1, 0, 1} ;
		int count = 0 ;
		for (auto it : operators) {
			int row = it[0] ;
			int col = it[1] ;
			if (visited[row][col] == 1) {
				ans.push_back(count) ;
				continue ;
			}
			visited[row][col] = 1 ;
			count++ ;
			for (int i = 0 ; i<4 ; i++) {
				int nr = row + rowmat[i] ;
				int nc = col + colmat[i] ;
				int u = row*m + col, v = nr*m + nc ;
				if (nr >= 0 && nr<n && nc >= 0 && nc<m && visited[nr][nc] == 1 && ds.findUparent(u) != ds.findUparent(v)) {
					count-- ;
					ds.unionBysize(u, v) ;
				}
			}
			ans.push_back(count) ;
		}
		return ans ;
	}
};


int main(){
vector<vector<int>> operators={{1,1},{0,1},{3,3},{3,4}} ;
int n = 4, m = 5;
Solution s;
vector<int> ans = s.numOfIslands(n, m, operators);
for(int i=0 ; i<ans.size() ; i++){
    cout << ans[i] << " ";
}
return 0 ;
}