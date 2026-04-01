#include<bits/stdc++.h>
using namespace std ;

int divisor(vector<int> &arr , int threshold , int mid){
    long long sum=0 ;
    for(int i=0 ; i<arr.size() ; i++){
        sum=sum+(long long)ceil(double(arr[i])/mid) ;
        if(sum>threshold) break;
    }
    if(sum<=threshold) return 1 ;
    return 0 ;
}
 
int divisor_for_threshold(vector<int> &arr , int threshold){
    long long ans=-1 ;
    int low=1 ;
    int high=*max_element(arr.begin() , arr.end()) ;
    while(low<=high){
        int mid=(low+high)/2 ;
        int div=divisor(arr , threshold , mid) ;
        if(div==1){
            ans=mid ;
            high=mid-1 ;
        }
        else low=mid+1 ;
    }
    return ans ;
}

int main(){
vector<int> arr={1 , 2 , 5 , 9} ;
int threshold=6 ;
cout<<divisor_for_threshold(arr , threshold) ;
return 0 ;
}