#include<bits/stdc++.h>
#include<cmath>
using namespace std ;
 
long long banana_per_hour(vector<int> &arr , int mid){
    long long temp=0 ;
    for(int i : arr){
        temp+=(i+(long long)mid-1)/mid ;
    }
    return temp ;
}

int koko_eating_banana(vector<int> &arr , int time){
    int n=arr.size();
    int low=1 , high=*max_element(arr.begin() , arr.end()) ;
    long long ans=high ;
    while(low<=high){
        int mid=low + (high-low)/2 ;
        long long bph=banana_per_hour(arr , mid) ;
        if(bph<=(long long)time){
            ans=mid ;
            high=mid-1 ;
        }
        else
            low=mid+1 ;
    }
    return ans ;
}

int main(){
vector<int> arr={805306368,805306368,805306368} ;
int time=1000000000 ;
cout<<koko_eating_banana(arr , time)<<" banana/hour";
return 0 ;
}