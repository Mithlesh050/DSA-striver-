#include<bits/stdc++.h>
using namespace std ;

void floydWarshall(vector<vector<double>> &dist) {
		int n = dist.size() ;
		for (int k = 0 ; k<n ; k++) {
			for (int i = 0 ; i<n ; i++) {
				for (int j = 0 ; j<n ; j++) {
				    if(dist[i][k]!=1e8 && dist[k][j]!=1e8)
					dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]) ;
				}
			}
		}		
	}

int main(){
    vector<vector<double>> dist = {{0, 4, 1e8, 5, 1e8},
                                {1e8, 0, 1, 1e8, 6}, 
                                {2, 1e8, 0, 3, 1e8}, 
                                {1e8, 1e8, 1, 0, 2}, 
                                {1, 1e8, 1e8, 4, 0}};
	floydWarshall(dist);
	for(int i=0 ; i<dist.size() ; i++){
		for(int j=0 ; j<dist[0].size() ; j++){
			cout<<dist[i][j]<<"   " ;
		}
		cout << endl;
	}
	return 0;
}