#include<bits/stdc++.h>
using namespace std ;

//with space
/*
void left_rotation(int arr[] , int n , int d){
    vector<int> temp ;
    for(int i=0 ; i<d%n ; i++){
        temp.push_back(arr[i]) ;
    }
int i ;
    for(i=0 ; i<n-(d%n) ; i++){
        arr[i]=arr[i+d%n] ;
    }
   for(int j=0 ; j<temp.size() ; j++){
       arr[i++]=temp[j] ;
    }
}
*/

//without space 
void left_rotation(int *arr , int n  , int d){
    reverse(arr , arr+(d%n)) ;
    reverse(arr+(d%n)+1 , arr+n) ;
    reverse(arr , arr+n) ;
}
 
int main(){
int n=7 ;
int d=1 ;
int arr[n]={1 , 2 , 3 , 4 , 5 , 6 , 7} ;
left_rotation(arr , n , d) ;
for(int i=0 ; i<n ; i++)
cout<<arr[i]<<" " ;
return 0 ;
}