#include<bits/stdc++.h>
using namespace std ;
 
//TC--> O(k) ;
/*
int kth_element(vector<int> &a , vector<int> &b , int k){
    int n1=a.size() , n2=b.size() ;
    int i=0 , j=0 , count=0;
    while(i<n1 && j<n2){
        if(a[i]<=b[j]){
            count++ ;
            if(count==k) return a[i] ;
            i++ ;
        }
        else{
            count++ ;
            if(count==k) return b[j] ;
            j++ ;
        }
    }
    while(i<n1){
        count++ ;
        if(count==k) return a[i] ;
        i++ ;
    }
    while(j<n2){
        count++ ;
        if(count==k) return b[j] ;
        j++ ; 
    }
    return 0 ;
}
*/

// TC --> O(log(min(n , m))) ;
int kth_element(vector<int> &a , vector<int> &b , int k){
    int n1=a.size() , n2=b.size() ;
        if(n1>n2) kth_element(b , a , k) ;
        int low=max(0 , k-n2) , high=min(k , n1) ;
        while(low<=high){
            int mid=(low+high)>>1 ;
            int l1=INT_MIN , l2=INT_MIN ;
            int r1=INT_MAX , r2=INT_MAX ;
            if(mid-1>=0) l1=a[mid-1] ;
            if(k-mid-1>=0) l2=b[k-mid-1] ;
            if(mid<n1) r1=a[mid] ;
            if(k-mid<n2) r2=b[k-mid] ;
            if(l1<=r2 && l2<=r1){
                return max(l1 , l2) ;
            }
            else if(l1>r2) high=mid-1 ;
            else low=mid+1 ;
        }
        return 0 ;
}

int main(){
vector<int> arr1={2 , 3 , 6 , 7 , 9} ;
vector<int> arr2={1 , 4 , 8 , 10} ;
int k=4 ;
cout<<kth_element(arr1 , arr2 , k) ;
return 0 ;
}