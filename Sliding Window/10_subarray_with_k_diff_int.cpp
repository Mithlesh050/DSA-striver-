#include<bits/stdc++.h>
using namespace std ;

// TC --> O(n^2) 
/*
int subarraysWithKDistinct(vector<int>& nums, int k) {
        int ans=0 ;
        for(int i=0 ; i<nums.size() ; i++){
            map<int , int> mp ;
            for(int j=i ; j<nums.size() ; j++){
                mp[nums[j]]++ ;
                if(mp.size()==k) ans++ ;
                else if(mp.size()>k) break ;
            }
        }
        return ans ;
    }
*/

// TC --> O(2n)
int subarrays_sum(vector<int> &arr , int k){
        int ans=0 ;
        int left=0 , right=0 ;
        unordered_map<int , int> mp ;
        while(right<arr.size()){
            mp[arr[right]]++ ;
            while(mp.size()>k){
                mp[arr[left]]-- ;
                if(mp[arr[left]]==0) mp.erase(arr[left]) ;
                left++ ;
            }
            ans=ans+(right-left+1) ;
            right++ ;
        }
        return ans ;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarrays_sum(nums , k)-subarrays_sum(nums , k-1) ;
    }


int main(){
vector<int> arr={1,2,1,2,3} ;
int k=2 ;
cout<<subarraysWithKDistinct(arr , k) ;
return 0 ;
}