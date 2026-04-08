#include<bits/stdc++.h>
using namespace std ;
 
int main(){
int n=7 , check=0;
int arr[n]={5 , 13 , 46 , 24 , 52 , 20 , 9};
for(int i=0 ; i<n ; i++){
    for(int j=0 ; j<n-i-1 ; j++){
        if(arr[j]>arr[j+1]){
         swap(arr[j] , arr[j+1]) ;
         check++ ;
        }
    }
    if(check==0) break ;
}
for(int i=0 ; i<n ; i++){
    cout<<arr[i]<<" " ;
}
return 0 ;
}