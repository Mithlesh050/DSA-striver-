#include<bits/stdc++.h>
using namespace std ;
 
//brute force TC --> O(n^2) ; 1st approach
/*
long double dis_bw_gas_station(vector<int> &arr , int k){
    int n=arr.size() ;
    if(n==1) return 0.0 ;
    vector<int> arr1(n-1 , 0) ;
    for(int i=1 ; i<=k ; i++){
        long double maxsec=-1 ;
        int  maxind=-1 ;
        for(int j=0 ; j<n-1 ; j++){
            long double diff=arr[j+1]-arr[j] ;
            long double seclen=diff/(long double)(arr1[j]+1) ;
            if(maxsec<seclen){
                maxsec=seclen ;
                maxind=j ;
            }
        }
        arr1[maxind]++ ;
    }
    long double ans=-1 ;
    for(int i=0 ; i<n-1 ; i++){
        long double diff=arr[i+1]-arr[i] ;
        long double seclen=diff/(long double)(arr1[i]+1) ;
        ans=max(ans , seclen) ;
    }
    return ans ;
}
*/
//2nd approach. TC --> O(nlogn)
long double dis_bw_gas_station(vector<int> &arr , int k){
    int n=arr.size() ;
    if(n==1) return 0.0 ;
    priority_queue<pair<long double , int>> pq ;
    vector<int> arr1(n-1 , 0) ;
    for(int i=0 ; i<n-1 ; i++){
       pq.push({arr[i+1]-arr[i] , i}) ;
    }
    for(int i=1 ; i<=k ; i++){
        auto tp=pq.top() ;
        pq.pop() ;
        int secind=tp.second ;
        arr1[secind]++ ;
        long double inidiff=arr[secind+1]-arr[secind] ;
        long double newsection=inidiff/(long double)(arr1[secind]+1) ;
        pq.push({newsection , secind}) ;
    }
    return pq.top().first ;
}

int main(){
vector<int> arr={1 , 13 , 17 , 23} ;
int k=5 ;
cout<<dis_bw_gas_station(arr , k) ;
return 0 ;
}