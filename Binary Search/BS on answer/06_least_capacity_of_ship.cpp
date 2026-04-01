#include<bits/stdc++.h>
using namespace std ;
 
int find_day(vector<int> &arr , int day , int mid){
    int sum=0 , count=0 ;
    for(int i=0 ; i<arr.size() ; i++){
        sum=sum+arr[i] ;
        if(sum==mid){
            sum=0 ;
            count++ ;
        }
        else if(sum>mid){
            count++ ;
            sum=arr[i] ;
        }
    }
    if(sum) count++ ;
    if(count<=day) return 1 ;
    return 0 ;
}

int capacity_of_ship(vector<int> &arr , int day){
    int ans=-1 ;
    int low=*max_element(arr.begin() , arr.end()) ;
    int high=0 ;
    for(int i=0 ; i<arr.size() ; i++) high=high+arr[i] ;
    while(low<=high){
        int mid=(low+high)/2 ;
        int fd=find_day(arr , day , mid) ;
        if(fd==1){
            ans=mid ;
            high=mid-1 ;
        }
        else low=mid+1 ;
    }
    return ans ;
}

int main(){
vector<int> arr={1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10} ;
int day=5 ;
cout<<capacity_of_ship(arr , day) ;
return 0 ;
}