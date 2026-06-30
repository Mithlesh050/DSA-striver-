#include<bits/stdc++.h>
using namespace std ;

class disjointSet {
    public :
	vector<int> size, parent ;
	disjointSet(int n) {
		size.resize(n+1, 1) ;
		parent.resize(n+1) ;
		for (int i = 0 ; i<=n ; i++) {
			parent[i] = i ;
		}
	}
	int findUparent(int node) {
		if (parent[node] == node)
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
	int kruskalsMST(int V, vector<vector<int>> &edges) {
		int ans = 0 ;
		disjointSet ds(V) ;
		vector<pair<int, pair<int, int>> > arr ;
		for (int i = 0 ; i<edges.size() ; i++) {
			arr.push_back({edges[i][2], {edges[i][0], edges[i][1]}}) ;
		}
		sort(arr.begin(), arr.end()) ;
		for (int i = 0 ; i<arr.size() ; i++) {
			int u = arr[i].second.first, v = arr[i].second.second ;
			if (ds.findUparent(u) != ds.findUparent(v)) {
				ans += arr[i].first ;
				ds.unionBysize(u, v) ;
			}
		}
		return ans ;
	}
};


int main(){
    Solution s;
    vector<vector<int>> edges = {{0, 1, 5}, {1, 2, 3}, {0, 2, 1}};
    int V = 3;
    cout << s.kruskalsMST(V, edges);
    return 0;
}