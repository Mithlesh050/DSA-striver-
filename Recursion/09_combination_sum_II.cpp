#include<bits/stdc++.h>
using namespace std ;

class Solution {
private :
    void f(int ind , int k , vector<int> &temp , vector<vector<int>> &ans , vector<int> &arr){
        if(k==0) {
            ans.push_back(temp) ;
            return ;
        }
        for(int i=ind ; i<arr.size() ; i++){
            if(i>ind && arr[i]==arr[i-1]) continue ;
            if(arr[i]>k) break ;
            temp.push_back(arr[i]) ;
            f(i+1 , k-arr[i] , temp , ans , arr) ;
            temp.pop_back() ;
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans ;
        vector<int> temp ;
        sort(candidates.begin() , candidates.end()) ;
        f(0 , target , temp , ans , candidates) ;
        return ans ;
    }
};

int main(){
Solution s ;
vector<int> arr={10,1,2,7,6,1,5} ;
int k=8 ;
vector<vector<int>>  ans = s.combinationSum2(arr , k) ;
for(int i=0 ; i<ans.size() ; i++){
    for(auto it : ans[i]) cout<<it<<" " ;
    cout<<endl ;
}
return 0 ;
}