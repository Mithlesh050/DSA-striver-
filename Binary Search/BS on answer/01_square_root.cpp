#include<bits/stdc++.h>
using namespace std ;
 
int square_root(int n){
    int low=1 , high=n  , sq=1;
    while(low<=high){
        int mid=(low+high)/2 ;
        if(mid*mid<=n){
            sq=mid ;
            low=mid+1 ;
        }
        else
         high=mid-1 ;
    }
    return sq ;
}

int main(){
int n=50 ;
cout<<square_root(n) ;
return 0 ;
}