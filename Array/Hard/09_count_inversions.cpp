#include<bits/stdc++.h>
using namespace std ;
 
int merge(vector<int> &arr , int l , int m , int h){
    int count=0 ;
    int i=l , j=m+1 ;
    vector<int> temp ;
    while(i<=m && j<=h){
        if(arr[i]<arr[j]){
            temp.push_back(arr[i]) ;
            i++ ;
        }
        else{
            temp.push_back(arr[j]) ;
            j++ ;
            count+=(m-i+1) ;
        }
    }
    while(i<=m){temp.push_back(arr[i]) ; i++ ;}
    while(j<=h){temp.push_back(arr[j]) ; j++ ;}
    for(int i=l ; i<=h ; i++){
        arr[i]=temp[i-l] ;
    }
    return count ;
}

int merge_sort(vector<int> &arr , int low , int high){
    int count=0 ;
    int mid=(low+high)/2 ;
    if(low>=high) return count ;
    count+=merge_sort(arr , low , mid) ;
    count+=merge_sort(arr , mid+1 , high);
    count+=merge(arr , low , mid , high) ;
    return count ;
}

// TC --> O(nlogn) & SC-->O(n)
int count_inversions(vector<int> &arr){
      return merge_sort(arr , 0 , arr.size()-1) ;
}



int main(){
vector<int> arr={7 , 3 , 4 , 5 , 6} ;
cout<<count_inversions(arr) ;
return 0 ;
}