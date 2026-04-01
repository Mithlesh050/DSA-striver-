// Lower Bound --> smallest index such that arr[i]>=key ;
// Upper Bound --> smallest index such that arr[i]>key ;
#include<bits/stdc++.h>
using namespace std ;
 
/*
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
*/

int upper_bound(vector<int> &arr , int key){
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

int main(){
vector<int> arr={1 , 2 , 3 , 3 , 7 , 8 , 9 , 9 , 9 , 11} ;
int key=7 ;
// cout<<"Lower Bound : "<<lower_bound(arr , key) ;
cout<<"Upper Bound : "<<upper_bound(arr , key) ;
return 0 ;
}