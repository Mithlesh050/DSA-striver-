#include<bits/stdc++.h>
using namespace std ;
   
bool can_we_place(vector<int> &arr , int cows , int x){
    int count=cows ;
    int j=1 , temp=0 ;
    while(j<arr.size() && count>1){
        if(arr[j]-arr[temp]>=x){
            count-- ;
            temp=j ;
        }
        j++ ; 
    }
    if(count==1) return 1 ;
    return 0 ;
}

// TC --> O(n^2) (brute force)
/*
int max_distance(vector<int> &arr , int cows){
    int n=arr.size() ;
    int ans=-1 ;
    for(int i=1 ; i<=(arr[n-1]-arr[0]) ; i++){
        if(can_we_place(arr , cows , i)){
            ans=i ;
        }
        else break;
    }
    return ans ;
}
*/
// TC --> O(nlogn)
int max_distance(vector<int> &arr , int cows){
    int n=arr.size() ;
    int ans=-1 ;
    int low=1 , high=arr[n-1]-arr[0];
    while(low<=high){
        int mid=(low+high)/2 ;
        if(can_we_place(arr , cows , mid)){
            ans=mid ;
            low=mid+1 ;
        }
        else high=mid-1 ;
    }
    return ans ;
}

int main(){
vector<int> arr={0 , 3 , 4 , 7 , 9 ,10} ;
int cows=4 ;
cout<<max_distance(arr , cows) ;
return 0 ;
}