#include<bits/stdc++.h>
using namespace std ;
 
// TC --> O(logn)
/*
int binary_search(vector<int> &arr , int target){
    int low=0 , high=arr.size()-1 ;
    while(low<=high){
        int mid=(low+high)/2 ;
        if(arr[mid]<target){
            low=mid+1 ;
        }
        else if(arr[mid]>target){
            high=mid-1 ;
        }
        else{
            return mid ;
        }
    }
    return -1 ;
}
*/
// recursive solution
int binary_search(vector<int> &arr , int target , int low , int high){
        int mid=(low+high)/2 ;
        if(low>high) return -1 ;
        if(arr[mid]==target) return mid ;
        if(arr[mid]<target) low=mid+1 ;
        else high=mid-1 ;
        binary_search(arr , target , low , high) ;
}

int main(){
vector<int> arr={3 , 4 , 6 , 7 , 9 , 12 , 16 , 17} ;
int target=12 ;
// cout<<"Target is at index "<<binary_search(arr , target) ;
cout<<"Target is at index "<<binary_search(arr , target , 0 , arr.size()-1) ;
return 0 ;
}