#include<bits/stdc++.h>
using namespace std ;

int lower_bound(vector<int> &arr , int key){
    int ans=arr.size() ;
    int low=0 , high=arr.size()-1 ;
    while(low<=high){
         int mid=(low+high)/2 ;
         if(arr[mid]<key) low=mid+1 ;
         else{
            ans=mid ;
            high=mid-1 ;
         }
    }
    return ans ;
}

int upper_bound(vector<int> &arr , int key){
    int ans=arr.size() ;
    int low=0 , high=arr.size()-1 ;
    while(low<=high){
         int mid=(low+high)/2 ;
         if(arr[mid]<=key) low=mid+1 ;
         else{
            ans=mid ;
            high=mid-1 ;
         }
    }
    return ans ;
}
 
vector<int> first_last_occurrence(vector<int> &arr , int key){
    vector<int> ans(2 , -1);
      int lb=lower_bound(arr , key); 
      if(lb==arr.size() || arr[lb]!=key) {
        return ans ;
      }
      else{
        ans[0]=lb ;
        ans[1]=upper_bound(arr , key)-1 ;
      }
      return ans ;
}

int main(){
vector<int> arr={2 , 4 , 6 , 8 , 8 , 8 , 11 , 13} ;
int key=12 ;
vector<int> ans=first_last_occurrence(arr , key) ;
for(auto i: ans) cout<<i<<" " ;
return 0 ;
}