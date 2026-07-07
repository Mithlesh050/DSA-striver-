#include<bits/stdc++.h>
using namespace std ;

class Solution{
  private :
    void f(int ind , int sum , int k , vector<int> &temp , vector<vector<int>> &ans , vector<int> &arr){
        if(ind==arr.size()){
            if(sum==k){
                ans.push_back(temp) ;
            }
            return ;
        }
        temp.push_back(arr[ind]) ;
        sum+=arr[ind] ;
        f(ind+1 , sum , k , temp , ans , arr) ;
        temp.pop_back() ;
        sum-=arr[ind] ;
        f(ind+1 , sum , k , temp , ans , arr) ;
    }
 public :
    vector<vector<int>> subseqsWithSumK(int k , vector<int> &arr){
        vector<vector<int>> ans ;
        vector<int> temp ;
        f(0 , 0 , k , temp , ans , arr) ;
        return ans ;
    }
};

int main(){
Solution s ;
vector<int> arr={1 , 2 , 1} ;
int k=2 ;
vector<vector<int>> ans=s.subseqsWithSumK(k , arr) ;
for(int i=0 ; i<ans.size() ; i++){
    for(int j=0 ; j<ans[i].size() ; j++){
        cout<<ans[i][j]<<" " ;
    }
    cout<<endl ;
}
return 0 ;
}