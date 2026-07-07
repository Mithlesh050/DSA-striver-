#include<bits/stdc++.h>
using namespace std ;

class Solution {
private :
    void f(int ind , int k , vector<int> &temp , vector<vector<int>> &ans , vector<int> &arr){  
        if(ind==arr.size()){
            if(k==0) ans.push_back(temp) ;
            return ;
        }
        if(arr[ind]<=k){
         temp.push_back(arr[ind]) ;
         f(ind , k-arr[ind] , temp , ans , arr) ;
         temp.pop_back() ;
        }
         f(ind+1  , k , temp , ans , arr) ;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans ;
        vector<int> temp ;
        f(0 , target , temp , ans , candidates) ;
        return ans ;
    }
};

int main(){
Solution s ;
vector<int> arr={2 , 3 , 6 , 7} ;
int target=7 ;
vector<vector<int>> ans=s.combinationSum(arr , target) ;
for(int i=0 ; i<ans.size() ; i++){
    for(auto it : ans[i]) cout<<it<<" " ;
    cout<<endl ;
}
return 0 ;
}