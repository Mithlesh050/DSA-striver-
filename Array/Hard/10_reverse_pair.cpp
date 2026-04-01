#include<bits/stdc++.h>
using namespace std ;
 
int check_pair(vector<int> &arr , int low , int mid , int high){
    int count=0 ;
    int j=mid+1 ;
    for(int i=low ; i<=mid ; i++){
        while(j<=high && arr[i]>2*arr[j]){
            j++ ;
        }
        count=count+(j-(mid+1)) ;
    } 
    return count ;
}

void merge(vector<int> &arr , int low , int mid , int high){
    int i=low , j=mid+1 ;
    vector<int> temp;
    while(i<=mid && j<=high){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]) ;
            i++ ;
        }
        else{
            temp.push_back(arr[j]) ;
            j++ ;
        }
    }
    while(i<=mid){temp.push_back(arr[i]) ; i++ ;}
    while(j<=high){temp.push_back(arr[j]) ; j++ ;}
    for(int i=low ; i<=high ; i++){
        arr[i]=temp[i-low] ;
    }
}


int merge_sort(vector<int> &arr , int low , int high){
    int mid=(low+high)/2 ;
    int count=0 ;
    if(low==high) return count ;
    count+=merge_sort(arr , low , mid) ;
    count+=merge_sort(arr , mid+1 , high) ;
    count+=check_pair(arr , low , mid , high) ;
    merge(arr , low , mid , high) ;
    return count ;
}

int reverse_pair(vector<int> &arr){
    return merge_sort(arr , 0 , arr.size()-1) ;
}

int main(){
vector<int> arr={40 , 25 , 19 , 12 , 9 , 6 , 2} ;
cout<<reverse_pair(arr) ;
return 0 ;
}