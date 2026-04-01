#include<bits/stdc++.h>
using namespace std ;
 

//optimal solution 1 . TC-->O(nlogn)
/*
void merge_array(vector<int> &a , vector<int> &b){
    int i=a.size()-1 , j=0 ;
    while(i>=0 && j<b.size()){
        if(a[i]>b[j]){
        swap(a[i] , b[j]) ;
        i-- ;
        j++ ;
        }
        else break;
    }
    sort(a.begin() , a.end()) ;
    sort(b.begin() , b.end()) ;
}
*/

//optimal 2 
void merge_array(vector<int> &a , vector<int> &b){
    int n=a.size() , m=b.size() ;
    int gap=(n+m)/2 + (n+m)%2;
    while(gap>0){
        int left=0 , right=left+gap ;
        while(right<(n+m)){
        if(left<n && right>=n){
            if(a[left]>b[right-n]){
                swap(a[left] , b[right-n]) ;
            }
        }
        else if(left<n && right<n){
            if(a[left]>a[right]){
                swap(a[left] , a[right]) ;
            }   
        }
        else{
            if(b[left-n]>b[right-n]){
                swap(a[left-n] , b[right-n]) ;
            }
        }
        left++ ;
        right++ ;
    }
        if(gap==1) break;
        gap=gap/2+gap%2 ;
    }
}


int main(){
vector<int> arr1={1 , 3 , 5 , 7} ;
vector<int> arr2={0 , 2 , 6 , 8 , 9} ;
merge_array(arr1 , arr2) ;
for(int i=0 ; i<arr1.size() ; i++) cout<<arr1[i]<<" " ;
for(int j=0 ; j<arr2.size() ; j++) cout<<arr2[j]<<" " ;
return 0 ;
}