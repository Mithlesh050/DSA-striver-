#include<bits/stdc++.h>
using namespace std ;

 int subarrays_with_xor_k(vector<int> &arr , int k){
    int xr=0  , count=0;
    unordered_map<int , int> mp ;
    mp[xr]++ ;
    for(int i=0 ; i<arr.size() ; i++){
        xr=xr^arr[i] ;
        if(mp.find(xr^k)!=mp.end()){
            count+=mp[xr^k] ;
        }
        mp[xr]++ ;
    }
    return count ;
 }

int main(){
vector<int> arr={4 , 2 , 2 , 6 , 4} ;
int key=6 ;
cout<<subarrays_with_xor_k(arr , key) ;
return 0 ;
}