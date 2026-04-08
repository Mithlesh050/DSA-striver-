#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;
 
void fibonacci(int n , int *arr , int size){
    int i=size-n+2 ;
    if(n<2) return ;
    arr[i]=arr[i-1]+arr[i-2] ;
    fibonacci(n-1 , arr , size) ;
}

int main(){
int n=15 ;
int arr[n]={0 , 1} ;
fibonacci(n , arr , n) ;
for(int i=0 ; i<n ; i++)
cout<<arr[i]<<" " ;
return 0 ;
}