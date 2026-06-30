#include<bits/stdc++.h>
using namespace std ;

class Solution {
	private:
	void dfs(int node, vector<vector<int>> &adj, vector<int> &visited, stack<int> &st) {
		visited[node] = 1 ;
		for (auto it : adj[node]) {
			if (visited[it] == 0) {
				dfs(it, adj, visited, st) ;
			}
		}
		st.push(node) ;
	}
	public:
	vector<int> topoSort(int V, vector<vector<int>> & edges) {
		vector<vector<int>> adj(V) ;
		for (int i = 0 ; i<edges.size() ; i++) {
			adj[edges[i][0]].push_back(edges[i][1]) ;
		}
		vector<int> visited(V, 0) ;
		stack<int> st ;
		for (int i = 0 ; i<V ; i++) {
		    if(visited[i]==0)
			dfs(i, adj, visited, st) ;
		}
		vector<int> ans ;
		while (!st.empty()) {
			ans.push_back(st.top()) ;
			st.pop() ;
		}
		return ans ;
	}
};


int main(){
Solution s ;
vector<vector<int>> edges = {{3, 0}, {1, 0}, {2, 0}};
int v = 4;
vector<int> ans = s.topoSort(v, edges);
for(auto it : ans)
    cout << it << " ";
return 0 ;
}