#include<bits/stdc++.h>
using namespace std ;
 
int main(){
int n=6 ;
int arr[n]={1 , 6 , 3 , 8 , 4 , 12} ;
int max=INT16_MIN ;
for(int i=0 ; i<n ; i++){
    if(max<arr[i]) max=arr[i] ;
}
cout<<"Largest element in given arrray is "<<max ;
return 0 ;
}