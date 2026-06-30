#include<bits/stdc++.h>
using namespace std ;

vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        int n = asteroids.size();
        for (int i = 0; i < n; i++) {
            int flag = 0;
            while (i < n && ans.size() > 0 && ans[ans.size() - 1]>0 && asteroids[i] < 0) {
                if (ans[ans.size() - 1] < abs(asteroids[i])) {
                    ans.pop_back();
                } 
                else if(ans[ans.size() - 1] == abs(asteroids[i])){
                    ans.pop_back() ;
                    i++ ;
                }
                else {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0 && i < n)
                ans.push_back(asteroids[i]);
        }
        return ans;
    }

int main(){
vector<int> arr={3,5,-6,2,-1,4} ;
vector<int> ans=asteroidCollision(arr) ;
for(auto it : ans) cout<<it<<" " ;
return 0 ;
}