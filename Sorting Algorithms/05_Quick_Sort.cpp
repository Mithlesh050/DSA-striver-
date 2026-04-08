#include<bits/stdc++.h>
using namespace std ;
 
int partition(int arr[] , int low , int high){
    int pivot=arr[low] ;
    int i=low , j=high ;
    while(i<j){
        while(arr[i]<pivot && i<=high) i++ ;
        while(arr[j]>pivot && j>=low) j-- ;
        if(i<j)
        swap(arr[i] , arr[j]) ;
    }
    return j ;
}

void quick_sort(int arr[] , int low , int high){
    if(low<high){
        int p=partition(arr , low , high) ;
        quick_sort(arr , low , p-1) ;
        quick_sort(arr , p+1 , high) ;
    }
}

int main(){
int n=9 ;
int arr[n]={5 , 13 , 46 , 24 , 52 , 20 , 9 , 85 , 70};
int low=0 , high=n-1;
quick_sort(arr , low , high) ;
for(int i=0 ; i<n ; i++)
cout<<arr[i]<<" " ;
return 0 ;
}