#include<bits/stdc++.h>
using namespace std ;
 
int main(){
int n=7 ;
int arr[n]={5 , 13 , 46 , 24 , 52 , 20 , 9};
for(int i=1 ; i<n ; i++){
    int j=i-1 ;
    while(j>=0 && arr[j]>arr[j+1]){
        swap(arr[j] , arr[j+1]);
        j-- ;
    }
}
for(int i=0 ; i<n ; i++){
    cout<<arr[i]<<" ";
}
return 0 ;
}