#include<bits/stdc++.h>
using namespace std ;

// TC --> O(n^2)
/*
int sumSubarrayMins(vector<int>& arr) {
        int ans=0 , mod=(int)(1e9+7) ;
        for(int i=0 ; i<arr.size() ; i++){
            int mini=arr[i] ;
            for(int j=i ; j<arr.size() ; j++){
                mini=min(mini , arr[j]) ;
                ans=(ans+mini)%mod ;
            }
        }
        return ans ;
    }
*/

// TC --> O(3n)
vector<int> findPSE(vector<int> &arr){
        int n=arr.size() ;
        vector<int> ans(n , -1) ;
        stack<int> st ;
        for(int i=0 ; i<n ; i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop() ;
            }
            if(!st.empty()) ans[i]=st.top() ;
            st.push(i) ;
        }
        return ans ;
    }
    vector<int> findNSE(vector<int> &arr){
        int n=arr.size() ;
        vector<int> ans(n , n) ;
        stack<int> st ;
        for(int i=n-1 ; i>=0 ; i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop() ;
            }
            if(!st.empty()) ans[i]=st.top() ;
            st.push(i) ;
        }
        return ans ;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int ans=0 , mod=(int)(1e9+7) ;
        vector<int> PSE=findPSE(arr) ;
        vector<int> NSE=findNSE(arr) ;
       for(int i=0 ; i<arr.size() ; i++){
        int left=i-PSE[i] , right=NSE[i]-i ;
        ans=(ans+(left*right*1LL*arr[i]))%mod ;
       }
       return ans ;
    }

int main(){
vector<int> arr={3,1,2,4} ;
cout<<sumSubarrayMins(arr) ;
return 0 ;
}