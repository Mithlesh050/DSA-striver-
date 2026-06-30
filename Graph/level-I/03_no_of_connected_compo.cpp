#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    void dfs(int node,vector<vector<int>>&adj,vector<int>&visited)
    {
       if(visited[node]==1) return;
       visited[node]=1;
       for(auto it:adj[node]) 
          dfs(it,adj,visited) ;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1)   
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int>visited(n,0);
        int count =0;
        for(int i=0;i<n;i++)
        {
            if(visited[i]==false)
            {
                count++;
                dfs(i,adj,visited);
            }
        }
        return count;
    }
};

int main(){
vector<vector<int>> arr={{1 , 1 , 0} , {1 , 1 , 0} , {0 , 0 , 1}} ;
Solution s ;
cout<<s.findCircleNum(arr) ;
return 0 ;
}