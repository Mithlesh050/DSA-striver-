#include<bits/stdc++.h>
using namespace std ;
// optimal 1 
/*
 vector<int> missing_and_repeating(vector<int> &arr){
    int n=arr.size() ;
    int m , r ;
    int sum=(n*(n+1))/2 ;
    int sqsum=sum*(2*n+1)/3 ;
    for(int i=0 ; i<n ; i++){
        sum=sum-arr[i] ;
        sqsum=sqsum-(arr[i]*arr[i]) ;
    }
    m=(sqsum/sum+sum)/2 ;
    r=m-sum ;
    vector<int> ans={m , r} ;
    return ans ;
 }
*/

//optimal 2 
vector<int> missing_and_repeating(vector<int> &arr){
    int n=arr.size() ;
    int m , r ;
    int xr=0 ;
    for(int i=0 ; i<n ; i++){
        xr=xr^arr[i] ;
        xr=xr^(i+1) ;
    }
    int bitNo=0 ;
    while(1){
        if((xr & 1<<bitNo)!=0)
        break ;
        bitNo++ ;
    }
    int zero=0 , one=0 ;
    for(int i=0 ; i<n ; i++){
        if((arr[i] & 1<<bitNo)!=0){
            one=one^arr[i] ;
        }
        else{
            zero=zero^arr[i] ;
        }
    }
    for(int i=1 ; i<=n ; i++){
        if((i & 1<<bitNo)!=0){
            one=one^i ;
        }
        else{
            zero=zero^i ;
        }
    }
    int count=0 ;
    for(int i=0 ;i<n ; i++){
        if(zero==arr[i]){
            count++ ;
            break;
        }
    }
    if(count>0){
        r=zero ;
        m=one ;
    }
    else{
        r=one;
        m=zero ;
    }
    vector<int> ans={m , r} ;
    return ans ;
 }


int main(){
vector<int> arr={4 , 3 , 6 , 2 , 1 , 1} ;
vector<int> ans=missing_and_repeating(arr) ;
cout<<"Missing element : "<<ans[0]<<endl ;
cout<<"Repeating element : "<<ans[1]<<endl ;
return 0 ;
}