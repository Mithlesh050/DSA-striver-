#include<bits/stdc++.h>
using namespace std ;

// TC--> O(n^3)
// int longest_subarray_with_sum_k(int n , int arr[] , int key){
//     int len=0 ;
//     for(int i=0 ; i<n ; i++){
//         for(int j=i ; j<n ; j++){
//              int k=i ;
//              int sum=0 ;
//              while(k<=j){
//                 sum+=arr[k++] ;
//              }
//              if(sum==key){
//                 if(len<k-i) len=k-i ;
//              }
//         }
//     }
//     return len ;
// }

//TC --> depends on ordered [O(nlogn)] or unordered map ([O(n^2)])
//  int longest_subarray_with_sum_k(int n , int arr[] , int key){
//     int maxlen=0 ;
//     int sum=0 ;
//     map<int , int> mpp ;
//     for(int i=0 ; i<n ; i++){
//         sum+=arr[i] ;
//         if(sum==key) maxlen=max(maxlen , i+1) ;
//         int rem=sum- key ;
//         if(mpp.find(rem) != mpp.end()){
//             int len=i-mpp[rem] ;
//             maxlen=max(maxlen , len) ;
//         }
//         if(mpp.find(sum)==mpp.end())
//         mpp[sum]=i ;
//     }
//     return maxlen ;
// }

//TC --> O(n)
 int longest_subarray_with_sum_k(int n , int arr[] , int key){
    int maxlen=0 ;
    int l=0  , r=0 ;
    int sum=arr[0];
    while(r<n){
        while(l<=r && sum>key){
            sum-=arr[l] ;
            l++ ;
        }
        if(sum==key)
        maxlen=max(maxlen , r-l+1) ;
        r++ ;
        if(r<n) sum+=arr[r] ;
    }
    return maxlen ;
}
 
int main(){
int n=8 ;
int arr[n]={19 , 23 , 15 , 6 , 6 , 2 , 28 , 2} ;
int k=2 ;
int ans=longest_subarray_with_sum_k(n , arr , k) ;
cout<<ans ;
return 0 ;
}