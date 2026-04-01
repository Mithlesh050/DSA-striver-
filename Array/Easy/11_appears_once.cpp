#include<bits/stdc++.h>
using namespace std ;

int appears_once(int n , int arr[]){
    for(int i=0 ; i<n-1 ; i++){
        if(arr[i]==arr[i+1]) i++ ;
        else return arr[i] ;
    }
    return 0 ;
}

int main(){
int n=7 ;
int arr[n]={1 , 1 , 2 , 2 , 3 , 4 , 4} ;
cout<<appears_once(n , arr) ;
return 0 ;
}