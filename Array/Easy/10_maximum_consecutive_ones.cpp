#include<bits/stdc++.h>
using namespace std ;

int max_conse_ones(int n , int arr[]){
    int max=-1 ;
    for(int i=0 ; i<n ; i++){
        if(arr[i]==1){
           int temp=0 ;
           while(arr[i]==1 && i<n){
                temp++ ;
                i++ ;
            }
        if(max<temp) max=temp ;
       }
    }
    return max ;
}
 
int main(){
int n=9 ;
int arr[n]={1 , 1 , 0 , 1 , 1 , 1 , 1 , 1  , 1} ;
int ans=max_conse_ones(n , arr);
cout<<ans<<" " ;
return 0 ;
}