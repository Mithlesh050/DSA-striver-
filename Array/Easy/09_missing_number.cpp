#include<bits/stdc++.h>
using namespace std ;

int missing_number(int n , int arr[]){
    int temp ;
    for(int i=0 ; i<n ; i++){
        if(arr[i]!=i+1) return i+1 ;
    }
    return 0 ;
}

int main(){
int n=7 ; 
int arr[n]={1 , 2 , 3 , 5 , 6 , 7 , 8} ;
int ans=missing_number(n , arr) ;
cout<<ans<<" " ;
return 0 ;
}