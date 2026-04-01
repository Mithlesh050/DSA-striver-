#include<bits/stdc++.h>
using namespace std ;

//Dutch national flag algorithm . TC--> O(n)
void sort_0s_1s_2s(int n , int arr[]){
    int low=0 , mid=0 , high=n-1 ;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[mid] , arr[low]) ;
            mid++ ;
            low++ ;
        }
        else if(arr[mid]==1){
            mid++ ;
        }
        else{
            swap(arr[mid] , arr[high]) ;
            high-- ;
        }  
    }
}
 
int main(){
int n=7 ;
int arr[n]={0 , 1 , 0 , 1 , 2 , 0 , 2 , 1} ;
sort_0s_1s_2s(n , arr) ;
for(int i=0 ; i<n ; i++)
cout<<arr[i]<<" " ;
return 0 ;
}