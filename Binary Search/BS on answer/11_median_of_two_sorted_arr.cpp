#include <bits/stdc++.h>
using namespace std;

// TC --> O(n+m) , SC--> O(m+n)
/*
 double median_of_arrays(vector<int> &arr1 , vector<int> &arr2){
    vector<int> temp ;
    int i=0 , j=0 ;
    while(i<arr1.size() && j<arr2.size()){
        if(arr1[i]<=arr2[j]){
            temp.push_back(arr1[i]) ;
            i++ ;
        }
        else{
            temp.push_back(arr2[j]) ;
            j++ ;
        }
    }
    while(i<arr1.size()){temp.push_back(arr1[i]) ; i++ ;}
    while(j<arr2.size()){temp.push_back(arr2[j]) ; j++ ;}
    int n=temp.size() ;
    if(n%2==1){
        return temp[n/2] ;
    }
    else{
        return (temp[n/2]+temp[(n/2)-1])/2.0 ;
    }
    return 0 ;
 }
*/

// TC --> O(n+m) && SC --> O(1)
/*
 double median_of_arrays(vector<int> &arr1 , vector<int> &arr2){
    int i=0 , j=0 , n=arr1.size()+arr2.size();
    int ind2=n/2 , ind1=ind2-1 , count=0;
    int ind1val=-1 , ind2val=-1 ;
    while(i<arr1.size() && j<arr2.size()){
        if(arr1[i]<=arr2[j]){
            if(count==ind1) ind1val=arr1[i] ;
            if(count==ind2) ind2val=arr1[i] ;
            count++ ;
            i++ ;
        }
        else{
            if(count==ind1) ind1val=arr2[j] ;
            if(count==ind2) ind2val=arr2[j] ;
            count++ ;
            j++ ;
        }
    }
    while(i<arr1.size()){
       if(count==ind1) ind1val=arr1[i] ;
        if(count==ind2) ind2val=arr1[i] ;
        count++ ;
        i++ ;
    }
    while(j<arr2.size()){
       if(count==ind1) ind1val=arr2[j] ;
        if(count==ind2) ind2val=arr2[j] ;
        count++ ;
        j++ ;
    }
    if(n%2==1){
        return ind2val ;
    }
    else{
        return (ind1val+ind2val)/2.0 ;
    }
    return 0 ;
 }
*/
// TC --> O(log(min(n , m)))
double median_of_arrays(vector<int> &a, vector<int> &b){
        int n1=a.size() , n2=b.size() ;
        if(n1>n2) median_of_arrays(b , a) ;
        int low=0 , high=n1 ;
        int n=(n1+n2+1)/2 ;
        while(low<=high){
            int mid=(low+high)>>1 ;
            int l1=INT_MIN , l2=INT_MIN ;
            int r1=INT_MAX , r2=INT_MAX ;
            if(mid-1>=0) l1=a[mid-1] ;
            if(n-mid-1>=0) l2=b[n-mid-1] ;
            if(mid<n1) r1=a[mid] ;
            if(n-mid<n2) r2=b[n-mid] ;
            if(l1<=r2 && l2<=r1){
                if((n1+n2)%2==1) return (double)max(l1 , l2) ;
                else return ((double)(max(l1, l2)+min(r1 , r2)))/2.0 ;
            }
            else if(l1>r2) high=mid-1 ;
            else low=mid+1 ;
        }
        return 0 ;
}

int main()
{
    vector<int> arr1 = {1, 3, 4, 7, 10, 12};
    vector<int> arr2 = {2, 3, 6, 15};
    cout << median_of_arrays(arr1, arr2);
    return 0;
}