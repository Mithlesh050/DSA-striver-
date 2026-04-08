#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;

void reverse_array(int *a , int l , int r) {
     if(l>=r) return ;
     swap(a[l] , a[r]) ;
     reverse_array(a , l+1 , r-1) ;
}
 
int main(){
int arr[]={1 , 2 , 3 , 4 , 5 , 6};
int l=0 ;
int r=sizeof(arr)/sizeof(arr[0]) - 1;
reverse_array(arr , l , r);
for(int i=0  ; i<=r ; i++){
    cout<<arr[i]<<" " ;
}
return 0 ;
}