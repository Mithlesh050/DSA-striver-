#include<bits/stdc++.h> 
using namespace std ;
// TC --> O(n^2) 
/*
int max_consecutive_ones(vector<int> &arr , int k){
    int ans=0 ;
      for(int i=0 ; i<arr.size() ; i++){
        int zero=0 ;
        for(int j=i ; j<arr.size() ; j++){
            if(arr[j]==0) zero++ ;
            if(zero<=k){
             ans=max(ans , j-i+1) ;
            }
            else
            break;
        }
      }
      return ans ;
}
*/

// two pointer , TC --> O(2N)
/*
int max_consecutive_ones(vector<int> &arr , int k){
    int ans=0 , zeros=0 ;
    int left=0 , right=0 ;
    while(right<arr.size()){
        if(arr[right]==0) zeros++ ;
        while(zeros>k){
            if(arr[left]==0) zeros-- ;
            left++ ;
        }
        ans=max(ans , right-left+1) ;
        right++ ;
    }
    return ans ;
}
*/
// sliding Window , TC --> O(n)
int max_consecutive_ones(vector<int> &arr , int k){
    int ans=0 , zeros=0 ,  left=0 , right=0 ;
    while(right<arr.size()){
        if(arr[right]==0) zeros++ ;
        if(zeros>k){
            if(arr[left]==0) zeros-- ;
            left++ ;
            right++ ;
        }
        else{
            ans=max(ans , right-left+1) ;
            right++ ;
        }
    }
    return ans ;
}

int main(){
   vector<int> arr={1 , 1 , 1 , 0 , 0 , 0 , 1 , 1 , 1 , 1 , 0} ;
   int k=2 ;
   cout<<max_consecutive_ones(arr , k) ;
   return 0 ;
}