#include<bits/stdc++.h>
using namespace std ;

vector<int> bellmanFord(int V, vector<vector<int>> & edges, int src) {
		vector<int> dist(V, 1e8) ;
		dist[src] = 0 ;
		for (int i = 0 ; i<V - 1 ; i++) {
			for (int i = 0 ; i<edges.size() ; i++) {
				if (dist[edges[i][0]] != 1e8 && dist[edges[i][0]]+edges[i][2]<dist[edges[i][1]])
					dist[edges[i][1]] = dist[edges[i][0]]+edges[i][2] ;
			}
		}
		int count = 0 ;
		for (int i = 0 ; i<edges.size() ; i++) {
			if (dist[edges[i][0]] != 1e8 && dist[edges[i][0]]+edges[i][2]<dist[edges[i][1]])
				return {-1} ;
		}
		return dist ;
	}

int main(){
    vector<vector<int>> edges = {{1, 3, 2}, {4, 3, -1}, {2, 4, 1}, {1, 2, 1}, {0, 1, 5}};
    int V=5  , src=0 ;
    vector<int> ans=bellmanFord(V , edges , src) ;
    for(auto it : ans)
        cout << it << " ";
    return 0;
}