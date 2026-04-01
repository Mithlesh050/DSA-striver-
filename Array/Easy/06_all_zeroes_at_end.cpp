#include<bits/stdc++.h>
using namespace std ;

void zeroes_at_end(int arr[] , int n){
    for(int i=0 ; i<n-1 ; i++){
        int j=i+1 ;
        if(arr[i]==0){
            while(arr[j]==0 && j<n) j++ ;
            if(j>=n) break;
            swap(arr[i] , arr[j]) ;
        }
    }
}
 
int main(){
int n=7 ;
int arr[n]={1 , 0 , 3 , 0 , 0 , 4 , 5} ;
zeroes_at_end(arr , n) ;

for(int i=0 ; i<n ; i++){
    cout<<arr[i]<<" " ;
}

return 0 ;
}