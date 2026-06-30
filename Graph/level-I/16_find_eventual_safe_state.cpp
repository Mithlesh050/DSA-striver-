#include<bits/stdc++.h>
using namespace std ;

class Solution {
    private :
	bool dfs(int node, vector<vector<int>> &graph, vector<int> &visited, vector<int> &path , vector<int> &check) {
		visited[node] = 1 ;
		path[node] = 1 ;
		for (auto it : graph[node]) {
			if (visited[it] == 0) {
				if (dfs(it, graph, visited, path , check))
					return true ;
			}
			else if (path[it])
				return true ;
		}
        check[node]=1 ;
		path[node] = 0 ;
		return false ;
	}
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size() ;
        vector<int> visited(n, 0) ;
		vector<int> path(n, 0) ;
        vector<int> check(n , 0) ;
		for (int i = 0 ; i<n ; i++) {
			if (visited[i] == 0) {
				dfs(i, graph, visited, path , check) ;
			}
		}
        vector<int> ans ;
		for(int i=0 ; i<graph.size() ; i++){
            if(check[i]==1) ans.push_back(i) ;
        }
        return ans ;
    }
};

int main(){
    Solution s;
    vector<vector<int>> graph = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
    vector<int> ans = s.eventualSafeNodes(graph);
    for(auto it : ans)
        cout << it << " ";
    return 0;
}