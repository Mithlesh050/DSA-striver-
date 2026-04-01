#include<bits/stdc++.h>
using namespace std ;
// TC --> O(n^2)
// vector<int> intersection_of_arrays(int n1 , int * arr1 , int n2 , int * arr2){
//     vector<int> v ;
//     for(int i=0 ; i<n1 ; i++){
//         for(int j=0 ; j<n2 ; j++){
//             if(arr1[i]==arr2[j]){
//                 v.push_back(arr1[i]) ;
//                 arr2[j]=0 ;
//                 break;
//             }
//         }
//     }
//     return v ;
// }

//TC --> O(n1+n2) ;
 vector<int> intersection_of_arrays(int n1 , int * arr1 , int n2 , int * arr2){
    vector<int> v ;
    int i=0 , j=0 ;
    while(i<n1 && j<n2){
        if(arr1[i]==arr2[j]){
            v.push_back(arr1[i]) ;
            i++ ;
            j++ ;
        }
        else if(arr1[i]<arr2[j]) i++ ;
        else j++ ;
    }
    return v ;
}
 
int main(){
int n1=5 , n2=7 ;
int arr1[n1]={1 , 2 , 3 , 5 , 6} ;
int arr2[n2]={1 , 2 , 4 , 5 , 6 , 7 , 8} ;
vector<int> ans=intersection_of_arrays(n1 , arr1 , n2 , arr2) ;
for(auto i : ans) cout<<i<<" " ;
return 0 ;
}