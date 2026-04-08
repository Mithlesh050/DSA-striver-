#include<bits/stdc++.h>
using namespace std ;
 
int main(){
int n=7 ;
int arr[n]={5 , 13 , 46 , 24 , 52 , 20 , 9};
int k=0 ;
for(int i=0 ; i<n ; i++){
    int min=INT16_MAX ;
    for(int j=i ; j<n ; j++){
        if(arr[j]<min){
            min=arr[j] ;
            k=j ;
        }
    }
    swap(arr[i] , arr[k]) ;
}
for(int i=0 ; i<6 ; i++)
cout<<arr[i]<<" ";
return 0 ;
}