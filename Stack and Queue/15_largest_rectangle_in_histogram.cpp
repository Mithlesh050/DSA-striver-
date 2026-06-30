#include<bits/stdc++.h>
using namespace std ;

int largestRectangleArea(vector<int>& heights) {
        int ans = INT_MIN;
        stack<int> st;
        for (int i = 0; i < heights.size(); i++) {
            while(!st.empty() && heights[st.top()] > heights[i]) {
                int top = st.top(), nse = i;
                st.pop();
                int pse = !st.empty() ? st.top() : -1;
                ans = max(ans, heights[top] * (nse - pse - 1));
            }
            st.push(i);
        }
        while (!st.empty()) {
            int top = st.top(), nse = heights.size();
            st.pop();
            int pse = !st.empty() ? st.top() : -1;
            ans = max(ans, heights[top] * (nse - pse - 1));
        }
        return ans ;
    }

int main(){
vector<int> arr={2,1,5,6,2,3} ;
cout<<largestRectangleArea(arr) ;
return 0 ;
}