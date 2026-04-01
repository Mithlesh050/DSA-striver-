#include<bits/stdc++.h>
using namespace std ;
 
int nthroot(int mid , int n , int key){
    long long pro=1 ;
    for(int i=0 ; i<n ; i++){
        pro=pro*mid ;
        if(pro>key) return 2 ;
    }
    if(pro==key) return 1 ;
    return 0 ;
}

int nth_root(int n , int key){
    int low=1 , high=key;
    while(low<=high){
        int mid=(low+high)/2 ;
        if(nthroot(mid , n , key)==1){
             return mid ;
        }
        else if(nthroot(mid , n , key)==0) low=mid+1 ;
        else
         high=mid-1 ;
    }
    return -1;
}

int main(){
int n=2 , key=16 ;
cout<<nth_root(n , key) ;
return 0 ;
}