#include<bits/stdc++.h>
using namespace std ;
 
vector<int> union_of_arrays(int n1 , int *arr1 , int n2 , int *arr2){
    vector<int> v ;
    int i=0 , j=0 ;
    if(arr1[i]<=arr2[j]) v.push_back(arr1[i++]) ;
    else v.push_back(arr2[j++]) ;
    while(i<n1 && j<n2){
        if(arr1[i]<=arr2[j]){
            if(v[v.size()-1]!=arr1[i])
            v.push_back(arr1[i]) ;
            i++ ;
        }
        else{
            if(v[v.size()-1]!=arr2[j])
            v.push_back(arr2[j]) ;
            j++ ;
        }
        
    }
    while(i<n1){
        if(arr1[i]!=v[v.size()-1]){
            v.push_back(arr1[i]) ;
        }
        i++ ;
    }
    while(j<n2){
        if(arr2[j]!=v[v.size()-1]){
            v.push_back(arr2[j]) ;
        }
        j++ ;
    }
    return v ;
}

int main(){
int n1=5 , n2=4 ;
int arr1[n1]={4 , 5 , 7 , 7 , 7} ;
int arr2[n2]={3 , 4 , 6 , 8} ;
vector<int> arr=union_of_arrays(n1 , arr1 , n2 , arr2) ;
for(auto i : arr) cout<<i<<" " ;
return 0 ;
}