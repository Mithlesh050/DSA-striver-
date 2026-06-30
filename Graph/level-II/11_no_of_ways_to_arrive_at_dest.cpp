#include<bits/stdc++.h>
using namespace std ;

 int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        vector<vector<pair<long long, int>>> adj(n);
        for (int i = 0; i < roads.size(); i++) {
            adj[roads[i][0]].push_back({roads[i][2], roads[i][1]});
            adj[roads[i][1]].push_back({roads[i][2], roads[i][0]});
        }

        vector<int> ways(n, 0);
        ways[0] = 1;
        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            long long d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if (d > dist[node])
                continue;
            for (auto it : adj[node]) {
                long long weight = it.first;
                int neighbor = it.second;

                if (dist[neighbor] > d + weight) {
                    dist[neighbor] = d + weight;
                    pq.push({dist[neighbor], neighbor});
                    ways[neighbor] = ways[node];
                } 
                else if (dist[neighbor] == d + weight) {
                    ways[neighbor] = (ways[neighbor] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }

int main(){
  vector<vector<int>> roads={{0,6,7},{0,1,2},{1,2,3},{1,3,3},{6,3,3},{3,5,1},{6,5,1},{2,5,1},{0,4,5},{4,6,2}} ;
  int n = 7;
  cout << countPaths(n, roads);
  return 0;
}