#include<bits/stdc++.h>
using namespace std ;

int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size() , m=heights[0].size() ;
        vector<vector<int>> effort(n , vector<int> (m , INT_MAX)) ;
        priority_queue<pair<int , pair<int , int>> , vector<pair<int , pair<int , int>>> , greater<pair<int , pair<int , int>>>> pq ;
        pq.push({0 , {0 , 0}}) ;
        effort[0][0]=0 ;
        int rowmat[]={-1 , 0 , 1 , 0} ;
        int colmat[]={0 , -1 , 0 , 1} ;
        while(!pq.empty()){
            auto it = pq.top() ;
            int e=it.first ;
            int row=it.second.first ;
            int col=it.second.second ;
            if(row==n-1 && col==m-1) return e;
            pq.pop() ;
            for(int i=0 ; i<4 ; i++){
                int nr=row+rowmat[i] ;
                int nc=col+colmat[i] ;
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int cef=max(e ,abs(heights[row][col]-heights[nr][nc])) ;
                    if(cef<effort[nr][nc]){
                    pq.push({cef , {nr , nc}}) ;
                    effort[nr][nc]=cef ;
                    }
                }
            }
        }
        return 0 ;
    }

int main(){
    vector<vector<int>> heights = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};
    cout << minimumEffortPath(heights);
    return 0;
}