#include<bits/stdc++.h>
using namespace std ;
class Solution {
	private :
	bool dfs(int node, vector<vector<int>> &edges, vector<int> &visited, vector<int> &path) {
		visited[node] = 1 ;
		path[node] = 1 ;
		for (auto it : edges[node]) {
			if (visited[it] == 0) {
				if (dfs(it, edges, visited, path))
					return true ;
			}
			else if (path[it])
				return true ;
		}
		path[node] = 0 ;
		return false ;
	}
	public:
	bool isCyclic(int V, vector<vector<int>> &edges) {
		vector<int> visited(V, 0) ;
		vector<int> path(V, 0) ;
		vector<vector<int>> adj(V) ;
		for (int i = 0 ; i<edges.size() ; i++) {
			adj[edges[i][0]].push_back(edges[i][1]);
		}
		for (int i = 0 ; i<V ; i++) {
			if (visited[i] == 0) {
				if (dfs(i, adj, visited, path))
					return true ;
			}
		}
		return false ;
	}
};


int main(){
    Solution s;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}, {2, 3}};
    int v = 4;
    bool ans = s.isCyclic(v , edges);
    if(ans)
        cout << "Cycle Found";
    else
        cout << "Cycle Not Found";
    return 0;
}