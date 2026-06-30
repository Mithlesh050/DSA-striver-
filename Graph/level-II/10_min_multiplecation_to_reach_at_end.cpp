#include<bits/stdc++.h>
using namespace std ;

int minSteps(vector<int>& arr, int start, int end) {
	    if(start==end) return 0 ;
		queue<pair<int, int>> q ;
		q.push({start, 0}) ;
		vector<int> dist(1000, INT_MAX) ;
		dist[start] = 0 ;
		while (!q.empty()) {
			int node = q.front().first ;
			int steps = q.front().second ;
			q.pop() ;
			for (int i = 0 ; i<arr.size() ; i++) {
				int num = (node*arr[i])%1000 ;
				if (steps + 1<dist[num]) {
					dist[num] = steps + 1 ;
					if (num == end)
						return steps + 1 ;
					q.push({num, steps + 1}) ;
				}
			}
		}
		return - 1 ;
	}

int main(){
    int start = 3, end = 30;
    vector<int> arr = {2, 5, 7};
    cout << minSteps(arr, start, end);
    return 0;
}