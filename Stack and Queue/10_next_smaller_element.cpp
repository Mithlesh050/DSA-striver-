#include<bits/stdc++.h>
using namespace std ;

vector<int> nextSmallerEle(vector<int>& arr) {
        stack<int> st ;
        vector<int> ans(arr.size() , -1) ;
        for(int i=arr.size()-1 ; i>=0 ; i--){
             while(!st.empty() && st.top()>arr[i]){
                st.pop() ;
            }
             if(!st.empty())
                ans[i]=st.top() ;
            st.push(arr[i]) ;
        }
       return ans ; 
    }

int main(){
vector<int> arr={4, 8, 5, 2, 25} ;
vector<int> ans=nextSmallerEle(arr) ;
for(auto it : ans) cout<<it<<" " ;
return 0 ;
}