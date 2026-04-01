#include<bits/stdc++.h>
using namespace std ;
 
//TC-->O(nlogn) 
// vector<int> two_sum(int n , int arr[] , int key){
//     vector<int> ans ;
//     map<int , int> mpp ;
//     for(int i=0 ; i<n ; i++){
//         int rem=key-arr[i] ;
//         if(mpp.find(rem)!=mpp.end()){
//             ans.push_back(mpp[rem]) ;
//             ans.push_back(i) ;
//             break;
//         }
//         mpp[arr[i]]=i ;
//     }
//     return ans ;
// }

//without hashmap 
bool two_sum(int n , vector<int> &arr , int key){
    sort(arr.begin() , arr.end()) ;
    bool ans=false ;
    int l=0 , r=n-1 ;
    while(l<r){
        if(key>arr[l]+arr[r]) l++ ;
        else if(key<arr[l]+arr[r]) r-- ;
        else{
            ans=true ;
            break;
        }
    }
    return ans ;
}

int main(){
int n=7 ;
vector<int> arr={2 , 6 , 5 , 8 , 11 , 13 , 4} ;
int key=19 ;
// vector<int> twoSum=two_sum(n , arr , key) ;
// for(auto i : twoSum)
// cout<<i<<" " ;
cout<<two_sum(n , arr , key ) ;
return 0 ;
}