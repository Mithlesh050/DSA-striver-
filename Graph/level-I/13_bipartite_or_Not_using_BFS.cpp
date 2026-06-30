#include<bits/stdc++.h>
using namespace std ;

class Solution {
private:
    bool check(int start, vector<vector<int>>& graph, vector<int>& color) {
        queue<int> q;
        q.push(start);
        color[start] = 0;
        while (!q.empty()) {
            int node = q.front();
            int c = color[node];
            q.pop();
            for (auto it : graph[node]) {
                if (color[it] == -1) {
                    q.push(it);
                    if (c == 0)
                        color[it] = 1;
                    else
                        color[it] = 0;
                } else if (c == color[it])
                    return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);
        for(int i=0 ; i<graph.size() ; i++){
            if(color[i]==-1){
                if(!check(i , graph , color)) return false ;
            }
        }
        return true ;
    }
};

int main(){
    Solution s;
    vector<vector<int>> graph = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
    bool ans = s.isBipartite(graph);
    if(ans)
        cout << "This graph is bipartite";
    else
        cout << "This graph is not bipartite";
    return 0;
}