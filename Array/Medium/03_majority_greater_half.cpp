#include<bits/stdc++.h>
using namespace std ;
//TC-->O(nlogn)
// int majority_greater_half(vector<int> &arr){
//     map<int , int> mpp ;
//     for(int i=0 ; i<arr.size() ; i++){
//         mpp[arr[i]]++ ;
//     }
//     for(auto i: mpp)
//     if(i.second>arr.size()/2)
//     return i.first ;
//     return -1 ;
// }

//moore's voting algo . TC--> O(n)
 int majority_greater_half(vector<int> &arr){
    int count=0 , ele;
    for(int i=0 ; i<arr.size() ; i++){
        if(count==0){
        ele=arr[i] ;
        count++ ;
        }
        else if(arr[i]==ele)
         count++ ;
        else {
           count-- ;
        }
    }
    int temp=0 ;
    for(int i=0 ; i<arr.size() ; i++){
        if(ele==arr[i]) temp++ ;
    }
    if(temp>arr.size()/2)
    return ele ;
    return -1 ;
}
 
int main(){
vector<int> arr={2 , 2 , 1 , 3 , 1 , 1 , 3 , 1 , 1};
cout<<majority_greater_half(arr) ;
return 0 ;
}