#include<bits/stdc++.h>
using namespace std ;

void merge(int arr[] , int low , int mid , int high){
    int i=low , j=mid+1 ;
    vector<int> temp ;
    while(i<=mid && j<=high){
        if(arr[i]<arr[j]){
           temp.push_back(arr[i]) ;
           i++ ;
        }
        else{
            temp.push_back(arr[j]) ;
            j++ ;
        }
    }
    while(i<=mid){temp.push_back(arr[i]) ; i++ ;}
    while(j<=high){temp.push_back(arr[j]) ; j++ ;}
    for(int i=low ; i<=high ; i++ )
    arr[i]=temp[i-low] ;
}
 
void merge_sort(int arr[] , int low , int high){
    int mid=(low+high)/2 ;
    if(low>=high) return ;
    merge_sort(arr , low , mid) ;
    merge_sort(arr , mid+1 , high);
    merge(arr , low , mid , high);
    
}


int main(){
int n=7 ;
int arr[n]={5 , 13 , 46 , 24 , 52 , 20 , 9};
int low=0 , high=n-1;
merge_sort(arr , low , high) ;
for(int i=0 ; i<n  ; i++)
cout<<arr[i]<<" " ;
return 0 ;
}