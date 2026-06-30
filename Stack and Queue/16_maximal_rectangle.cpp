#include<bits/stdc++.h>
using namespace std ;

int rectangleArea(vector<int>& arr) {
        int ans = INT_MIN, n = arr.size();
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                int index = st.top(), nsi = i;
                st.pop();
                int psi = !st.empty() ? st.top() : -1;
                ans = max(ans, arr[index] * (nsi - psi - 1));
            }
            st.push(i) ;
        }
        while (!st.empty()) {
            int index = st.top(), nsi = n;
            st.pop();
            int psi = !st.empty() ? st.top() : -1;
            ans = max(ans, arr[index] * (nsi - psi - 1));
        }
        return ans;
    }

    int maximalRectangle(vector<vector<int>>& matrix) {
        int ans = INT_MIN;
        for (int i = 0; i < matrix[0].size(); i++) {
            for (int j = 1; j < matrix.size(); j++) {
                if (matrix[j][i] && matrix[j - 1][i]) {
                    matrix[j][i] += matrix[j - 1][i];
                }
            }
        }
        for (int i = 0; i < matrix.size(); i++) {
            ans = max(ans, rectangleArea(matrix[i]));
        }
        return ans;
    }

int main(){
vector<vector<int>> arr={{1 , 0 , 1 , 0 , 0} , 
                         {1 , 0 , 1 , 1 , 1} ,
                         {1 , 1 , 1 , 1 , 1} , 
                         {1 , 0 , 0 , 1 , 0} } ;
cout<<maximalRectangle(arr) ;
return 0 ;
}