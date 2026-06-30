#include<bits/stdc++.h>
using namespace std ;

vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for (int i = 2*n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums[i%n]) {
                st.pop();
            }
            if (!st.empty() && i<n)
                ans[i] = st.top();
            st.push(nums[i%n]);
        }
        return ans;
    }

int main(){
vector<int> arr={1,2,3,4,3} ;
vector<int> ans=nextGreaterElements(arr) ;
for(auto it : ans) cout<<it<<" " ;
return 0 ;
}