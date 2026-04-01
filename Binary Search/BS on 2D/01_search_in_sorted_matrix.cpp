#include<bits/stdc++.h>
using namespace std ;
 
// TC --> O(log(n*m))
bool matSearch(vector<vector<int>> &mat, int x) {
        int n=mat.size() , m=mat[0].size() ;
         int low=0 , high=n*m-1 ;
        while(low<=high){
            int mid=(low+high)/2 ;
            int row=mid/m , col=mid%m ;
            if(x==mat[row][col])
            return true ;
            else if(mat[row][col]<x) low=mid+1 ;
            else high=mid-1 ;
        }
    return false ;
 }

int main(){
vector<vector<int>> arr={{18 , 21 , 27 , 38 , 55 , 67}} ;
int x=55 ;
cout<<matSearch(arr , x) ;
return 0 ;
}