#include<bits/stdc++.h>
using namespace std ;
 
// TC --> O(n^2)
/*
int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count=0 ;
        for(int i=0 ; i<nums.size() ; i++){
            int sum=0 ;
            for(int j=i ; j<nums.size() ; j++){
                sum+=nums[j] ;
                if(sum==goal) count++ ;
                else if(sum>goal) break ;
            }
        }
        return count ;
    }
*/

// TC --> O(2n)
int subarrays_sum(vector<int>& nums, int goal) {
        if(goal<0) return 0 ;
        int count=0 ;
        int left=0 , right=0 , sum=0;
        while(right<nums.size()){
            sum=sum+nums[right] ;
            while(sum>goal){
                sum=sum-nums[left] ;
                left++ ;
            }
            count=count+(right-left+1) ;
            right++ ;
        }
        return count ;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return subarrays_sum(nums , goal)-subarrays_sum(nums , goal-1) ;
    }

int main(){
vector<int> arr={1,0,1,0,1} ;
int k=2 ;
cout<<numSubarraysWithSum(arr , k) ;
return 0 ;
}