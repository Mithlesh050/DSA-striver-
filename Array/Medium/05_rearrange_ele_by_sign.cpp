#include<bits/stdc++.h>
using namespace std ;
 
//TC --> O(2n) && SC--> O(n)
// void rearrange_by_sign(vector<int> &arr){
//     vector<int> posi ;
//     vector<int> niga ;
//     for(int i=0 ; i<arr.size() ; i++){
//         if(arr[i]>=0) posi.push_back(arr[i]) ;
//         else niga.push_back(arr[i]) ;
//     }
//     int k=0 , m=0 ;
//     for(int i=0 ; i<arr.size() ; i++){
//          if(i%2==0) arr[i]=posi[k++];
//          else arr[i]=niga[m++] ;
//     }
    
// }

void rearrange_by_sign(vector<int> & arr){
    vector<int> ans(arr.size() , 0) ;
    int posi=0 , nega=1 ;
    for(int i=0 ; i<arr.size() ; i++){
        if(arr[i]>=0){
            ans[posi]=arr[i] ;
            posi+=2 ;
        }
        else{
            ans[nega]=arr[i] ;
            nega+=2 ;
        }
    }
    for(int i=0 ; i<arr.size() ; i++)
    arr[i]=ans[i] ;
}

int main(){
vector<int> arr={3 , 1 , -2 , -5 , 2 , -4} ;
rearrange_by_sign(arr) ;
for(auto i: arr)
cout<<i<<" " ;
return 0 ;
}