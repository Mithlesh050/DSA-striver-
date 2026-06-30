#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans ;
        int temp=0 ;
        for(int i=0 ; i<nums.size() ; i++){
            temp=temp^nums[i] ;
        }
        unsigned setbit= temp & -(unsigned int)temp;
        int b1=0 , b2=0 ;
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i] & setbit){
                b1=b1^nums[i] ;
            }
            else b2=b2^nums[i] ;
        }
        ans.push_back(b1) ;
        ans.push_back(b2) ;
        return ans ;
    }
};

int main(){
Solution s ;
vector<int> nums={1,2,1,3,2,5} ;
vector<int> ans = s.singleNumber(nums) ;
cout<<ans[0]<<" "<<ans[1] ;
return 0 ;
}