#include<bits/stdc++.h>
using namespace std ;
// for unique elements
/*
int search_in_rotated_array(vector<int>&arr , int key){
    int low=0 , high=arr.size()-1 ;
    while(low<=high){
        int mid=(low+high)/2 ;
        if(arr[mid]==key) return mid ;
        if(arr[low]<=arr[mid]){
            if(arr[low]<=key && arr[mid]>=key){
                high=mid-1 ;
            }
            else low=mid+1 ;
        }
        else{
            if(arr[mid]<=key && arr[high]>=key){
                low=mid+1 ;
            }
            else high=mid-1 ;
        }
    }
    return -1 ;
}
*/

//for duplicate elements also 
 int search_in_rotated_array(vector<int>&arr , int key){
    int low=0 , high=arr.size()-1 ;
    while(low<=high){
        int mid=(low+high)/2 ;
        if(arr[mid]==key) return mid ;
        if(arr[mid]==arr[low] && arr[mid]==arr[high]){
            low++ ;
            high-- ;
            continue;
        }
        if(arr[low]<=arr[mid]){
            if(arr[low]<=key && arr[mid]>=key){
                high=mid-1 ;
            }
            else low=mid+1 ;
        }
        else{
            if(arr[mid]<=key && arr[high]>=key){
                low=mid+1 ;
            }
            else high=mid-1 ;
        }
    }
    return -1 ;
}
 
int main(){
vector<int> arr={7 , 8 , 9 , 1 , 2 , 3 , 4 , 5 , 6} ;
int key=8 ;
cout<<search_in_rotated_array(arr , key) ;
return 0 ;
}