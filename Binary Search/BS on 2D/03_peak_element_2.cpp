#include<bits/stdc++.h>
using namespace std ;
 
int findmax(vector<vector<int>> &arr , int mid){
        int max=INT_MIN , index;
          for(int i=0 ; i<arr.size() ; i++){
                if(max<arr[i][mid]){
                     max=arr[i][mid] ;
                     index=i ;
                }
          }
          return index ;
    }
// TC --> 
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        vector<int> ans={-1 , -1} ;
        int n=mat.size() , m=mat[0].size() ;
        int low=0 , high=m-1 ;
        while(low<=high){
            int mid=(low+high)/2 ;
            int maxrowIndex=findmax(mat , mid) ;
            int left=mid-1>=0 ? mat[maxrowIndex][mid-1] : -1 ;
            int right=mid+1<m ? mat[maxrowIndex][mid+1] : -1 ;
            if(mat[maxrowIndex][mid]>left && mat[maxrowIndex][mid]>right){
                ans[0]=maxrowIndex ;
                ans[1]=mid ;
                break ;
            }
            else if(mat[maxrowIndex][mid]<left) high=mid-1 ;
            else low=mid+1 ;
        }
        return ans ;
    }

int main(){
vector<vector<int>> arr={{1 , 4} , {3 , 2}} ;
vector<int> ans=findPeakGrid(arr) ;
for(auto i : ans) cout<<i<<" " ;
return 0 ;
}