#include<bits/stdc++.h>
using namespace std ;

/* class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0 ;
        for(int i=0 ; i<32 ; i++){
            int count=0 ;
            for(int j=0 ; j<nums.size() ; j++){
                if(nums[j]&(1<<i)) count++ ;
            }
            if(count%3) ans = ans | (1<<i) ;
        }
        return ans ;
    }
}; */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size() ;
        sort(nums.begin() , nums.end()) ;
        for(int i=1 ; i<n ; i=i+3){
            if(nums[i]!=nums[i-1]) return nums[i-1] ;
        }
        return nums[n-1] ;
    }
};

int main(){
Solution s ;
vector<int> nums={0,1,0,1,0,1,99} ;
cout<<s.singleNumber(nums) ;
return 0 ;
}