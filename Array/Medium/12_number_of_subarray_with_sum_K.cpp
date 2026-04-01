#include<bits/stdc++.h>
using namespace std ;
 

//TC --> O(nlogn) && SC --> O(n) ;
int no_of_subarray_sum_k(vector<int> &arr , int k){
    int count=0 , prefixsum=0 ;
    unordered_map<int , int> mp ;
    mp[prefixsum]++ ;
    for(int i=0 ; i<arr.size() ; i++){
        prefixsum+=arr[i] ;
        if(mp.find(prefixsum-k)!=mp.end())
        count+=mp[prefixsum-k] ;
        mp[prefixsum]++ ;
    }
    return count ;
}

int main(){
vector<int> arr={1 , 2 , 3 , -3 , 1 , 1 , 1 , 4 , 2 , -3};
int key=3 ;
cout<<no_of_subarray_sum_k(arr , key);
return 0 ;
}