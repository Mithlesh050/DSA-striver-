#include<bits/stdc++.h>
using namespace std ;

//without duplicates
/*
int min_in_ratated_array(vector<int> & arr){
    int ans=INT_MAX ;
    int low=0 , high=arr.size()-1 ;
    while(low<=high){
        int mid=(low+high)/2 ;
        if(arr[low]<=arr[high]) {
            ans=min(ans , arr[low]) ;
            break ;
        }
        if(arr[low]<=arr[mid]){
            ans=min(ans , arr[low]) ;
            low=mid+1 ;
        }
        else{
            ans=min(ans , arr[mid]) ;
            high=mid-1 ;
        }
    }
    return ans ;
}
*/

//with duplicates
int min_in_ratated_array(vector<int> & arr){
    int ans=INT_MAX ;
    int low=0 , high=arr.size()-1 ;
    while(low<=high){
        int mid=(low+high)/2 ;
        if(arr[low]==arr[mid] && arr[mid]==arr[high]){
            ans=min(ans , arr[low]) ;
            low++ ;
            high-- ;
            continue;
        }
        if(arr[low]<=arr[mid]){
            ans=min(ans , arr[low]) ;
            low=mid+1 ;
        }
        else{
            ans=min(ans , arr[mid]) ;
            high=mid-1 ;
        }
    }
    return ans ;
}

int main(){
vector<int> arr={7 , 8 , 1 , 2 , 3 , 4 , 5 , 6} ;
cout<<min_in_ratated_array(arr) ;
return 0 ;
}