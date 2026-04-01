#include<bits/stdc++.h>
using namespace std ;
 
int main(){
int n=8 ;
int arr[n]={1 , 2 , 3 , 4 , 4 , 5 , 8 , 8} ;
int count=0 ;
for(int i=0 ; i<n-1 ; i++){
    if(arr[i]>arr[i+1]){
        count++ ;
        break;
    }
}
if(count==0) cout<<"Sorted"<<endl  ;
else cout<<"Not Sorted"<<endl ; 
return 0 ;
}