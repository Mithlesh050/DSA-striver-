#include<bits/stdc++.h>
using namespace std ;

bool possible_toMake_bouquets(vector<int> &arr , int flow , int bou , int mid){
    int ans=0 , count=0 ;
    for(int i=0 ; i<arr.size() ; i++){
        if(arr[i]<=mid){
            count++ ;
        }
        else{
            if(count)
            ans=ans+count/flow ;
            count=0 ;
        }
    }
    if(count) ans=ans+count/flow ;
    if(ans>=bou) return true ;
    return false ;
}
 
int min_day_toMake_mBouquets(vector<int> &arr , int flow , int bou){
    int ans=-1 , n=arr.size() ;
    int low=*min_element(arr.begin() , arr.end()) ;
    int high=*max_element(arr.begin() , arr.end()) ;
    while(low<=high){
        int mid=(low+high)/2 ;
        int check=possible_toMake_bouquets(arr , flow , bou , mid) ;
        if(check==1){
            ans=mid ;
            high=mid-1 ;
        }
        else low=mid+1 ;
    }
    return ans ;
}

int main(){
vector<int> arr={7 , 7 , 7 , 7 , 13 , 11 , 12 , 7} ;
int flowers=3 , bouquets=2 ;
cout<<min_day_toMake_mBouquets(arr , flowers , bouquets) ;
return 0 ;
}