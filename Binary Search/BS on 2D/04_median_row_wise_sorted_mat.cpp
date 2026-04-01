#include<bits/stdc++.h>
using namespace std ;
 
int upperBound(vector<int> &arr , int key){
    int ans=arr.size() ;
    int low=0 , high=arr.size()-1 ;
    while(low<=high){
        int mid=(low+high)/2 ;
        if(arr[mid]<=key) low=mid+1 ;
        else {
            ans=mid ;
            high=mid-1 ;
        }
    }
    return ans ;
}
  
  
    int lte(vector<vector<int>> &mat , int mid){
        int count=0 ;
        for(int i=0 ; i<mat.size() ; i++){
            count=count+upperBound(mat[i] , mid) ;
        }
        return count ;
    }  

int median(vector<vector<int>> &mat) {
    int n=mat.size() ;
    int m=mat[0].size() ;
    int low=INT_MAX , high=INT_MIN ;
    for(int i=0 ; i<n ; i++){
        low=min(low , mat[i][0]) ;
        high=max(high , mat[i][m-1]) ;
    }
    int req=(n*m)/2 ;
    while(low<=high){
        int mid=(low+high)/2 ;
        int lessthenequal=lte(mat , mid) ;
        if(lessthenequal<=req) low=mid+1 ;
         else high=mid-1 ;
    }
    return low ;
}

int main(){
vector<vector<int>> arr={{1, 3, 5}, 
                         {2, 6, 9}, 
                         {3, 6, 9}} ;
cout<<median(arr) ;
return 0 ;
}