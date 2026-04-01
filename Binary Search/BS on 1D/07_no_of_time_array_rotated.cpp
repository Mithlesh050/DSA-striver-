#include<bits/stdc++.h>
using namespace std ;
 
int no_of_time_array_ratated(vector<int> &arr){
    int mini=INT_MAX , ans=-1 ;
    int low=0 , high=arr.size()-1 ;
    while(low<=high){
        int mid=(low+high)/2 ;
        if(arr[low]<=arr[high]){
            if(mini>arr[low]){
                mini=min(mini , arr[low]) ;
                ans=low ;
                break;
            }
        }
        if(arr[low]<=arr[mid]){
           if(mini>arr[low]){
                mini=min(mini , arr[low]) ;
                ans=low ;
            } 
            low=mid+1 ;
        }
        else{
            if(mini>arr[mid]){
                mini=min(mini , arr[mid]) ;
                ans=mid ;
            }
            high=mid-1 ;
        }
    }
    return ans ;
}

int main(){
vector<int> arr={3 , 4 , 5 , 1 , 2} ;
cout<<no_of_time_array_ratated(arr) ;
return 0 ;
}