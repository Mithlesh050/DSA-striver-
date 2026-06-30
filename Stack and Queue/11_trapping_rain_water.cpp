#include<bits/stdc++.h>
using namespace std ;

// TC --> O(3n) && SC--> O(2n)
/*
vector<int> prefixMax(vector<int> &arr){
        int n=arr.size() ;
        vector<int> ans(n , 0) ;
        ans[0]=arr[0] ;
        for(int i=1 ; i<arr.size() ; i++){
            ans[i]=max(ans[i-1] , arr[i]) ;
        }
        return ans ;
    }
    
    vector<int> suffixMax(vector<int> &arr){
        int n=arr.size() ;
        vector<int> ans(n , 0) ;
        ans[n-1]=arr[n-1];
        for(int i=n-2 ; i>=0 ; i--){
            ans[i]=max(arr[i] , ans[i+1]) ;
        }
        return ans ;
    }
    
    int trap(vector<int>& height) {
        int ans=0 ;
        vector<int> preMax=prefixMax(height) ;
        vector<int> suffMax=suffixMax(height) ;
        for(int i=0 ; i<height.size() ; i++){
            if(height[i]<preMax[i] && height[i]<suffMax[i]){
                ans=ans+min(preMax[i] , suffMax[i])-height[i] ;
            }
        }
        return ans ;
    }
*/

// TC-->O(n) && SC-->O(1) ;
int trap(vector<int>& height) {
        int leftmax = 0, rightmax = 0, ans = 0, l = 0, r = height.size() - 1;
        while (l < r) {
            if (height[l] <= height[r]) {
                if (leftmax > height[l]) {
                    ans += (leftmax - height[l]);
                } else {
                    leftmax = height[l];
                }
                l++;
            } else {
                if (rightmax > height[r]) {
                    ans += (rightmax - height[r]);
                } else {
                    rightmax = height[r];
                }
                r--;
            }
        }
        return ans ;
    }

int main(){
vector<int> arr={0,1,0,2,1,0,1,3,2,1,2,1} ;
cout<<trap(arr) ;
return 0 ;
}