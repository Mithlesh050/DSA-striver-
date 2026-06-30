#include<bits/stdc++.h>
using namespace std ;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses) ;
        vector<int> indegree(numCourses , 0) ;
        for(int i=0 ; i<prerequisites.size() ; i++){
               adj[prerequisites[i][0]].push_back(prerequisites[i][1]) ;
               indegree[prerequisites[i][1]]++ ;
        }
        queue<int> q ;
        for(int i=0 ; i<numCourses ; i++){
            if(indegree[i]==0) q.push(i) ;
        }
        int count=0 ;
        while(!q.empty()){
            int node=q.front() ;
            q.pop() ;
            count++ ;
            for(auto it : adj[node]){
                indegree[it]-- ;
                if(indegree[it]==0) q.push(it) ;
            }
        }
        if(numCourses==count) return true ;
        return false ;
    }

int main(){
    vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};
    int numCourses = 2;
    cout << canFinish(numCourses, prerequisites);
    return 0;
}