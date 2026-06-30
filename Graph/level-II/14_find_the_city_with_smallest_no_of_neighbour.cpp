#include<bits/stdc++.h>
using namespace std ;

int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int m=edges.size() ;
        vector<vector<int>> adj(n , vector<int>(n , INT_MAX)) ;
        for(int i=0 ; i<n ; i++) adj[i][i]=0 ;
        for(int i=0 ; i<m ; i++){
            adj[edges[i][0]][edges[i][1]]=edges[i][2] ;
            adj[edges[i][1]][edges[i][0]]=edges[i][2] ;
        }
        for(int k=0 ; k<n ; k++){
            for(int i=0 ; i<n ; i++){
                for(int j=0 ; j<n ; j++){
                    if(adj[i][k]!=INT_MAX && adj[k][j]!=INT_MAX)
                    adj[i][j]=min(adj[i][j] , adj[i][k]+adj[k][j]) ;
                }
            }
        }
        int cityno , citycount=n ;
        for(int i=0 ; i<n ; i++){
            int count=-1 ;
            for(int j=0 ; j<n ; j++){
                if(adj[i][j]<=distanceThreshold) count++ ;
            }
            if(citycount>=count){
                citycount=count ;
                cityno=i ;
            }
        }
        return cityno ;
    }

int main(){
    vector<vector<int>> edges = {{0, 1, 2}, {0, 4, 8}, {1, 2, 3}, {1, 4, 2}, {2, 3, 1}, {3, 4, 1}};
    int n = 5, distanceThreshold = 2;
    cout << findTheCity(n, edges, distanceThreshold);
    return 0;
}