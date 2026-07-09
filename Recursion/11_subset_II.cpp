#include<bits/stdc++.h>
using namespace std ;

/* class Solution {
private :
    void f(int ind , vector<int> &temp , set<vector<int>> &ans , vector<int> &nums){
        if(ind==nums.size()){
            ans.insert(temp) ;
            return ;
        }
        temp.push_back(nums[ind]) ;
        f(ind+1 , temp , ans , nums) ;
        temp.pop_back() ;
        f(ind+1 , temp , ans , nums) ;
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans ;
        set<vector<int>> st ;
        vector<int> temp ;
        sort(nums.begin() , nums.end())  ;
        f(0 , temp , st , nums) ;
        for(auto it : st) ans.push_back(it) ;
        return ans ;
    }
}; */

class Solution {
private :
    void f(int ind , vector<int> &temp , vector<vector<int>> &ans , vector<int> &nums){
        ans.push_back(temp) ;
        for(int i=ind ; i<nums.size() ; i++){
            if(i>ind && nums[i]==nums[i-1]) continue ;
            temp.push_back(nums[i]) ;
            f(i+1 , temp , ans , nums) ;
            temp.pop_back() ;
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() , nums.end()) ;
        vector<int> temp ;
        vector<vector<int>> ans ;
        f(0 , temp , ans , nums) ;
        return ans ;
    }
};

int main(){
Solution s ;
vector<int> nums={1 , 2 , 2} ;
vector<vector<int>> ans=s.subsetsWithDup(nums) ;
for(int i=0 ; i<ans.size() ; i++){
    for(auto it : ans[i]) cout<<it<<" " ;
    cout<<endl ;
}
return 0 ;
}