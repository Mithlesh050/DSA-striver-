#include<bits/stdc++.h>
using namespace std ;
 
int kth_missing_number(vector<int> &arr , int k){
    int n=arr.size() ;
    int low=0 , high=n-1 ;
    while(low<=high){
        int mid=(low+high)/2 ;
        int missing=arr[mid]-(mid+1) ;
        if(missing<k){
            low=mid+1 ;
        }
        else high=mid-1 ;
    }
    return high+1+k ;
}

int main(){
vector<int> arr={4 , 7 , 8} ;
int k=3 ;
cout<<kth_missing_number(arr , k) ;
return 0 ;
}