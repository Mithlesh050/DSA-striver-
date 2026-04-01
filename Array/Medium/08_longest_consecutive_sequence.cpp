#include<bits/stdc++.h>
using namespace std ;
//TC--> O(nlogn)
/*
int longest_consecutive_sequence(vector<int> &arr){
    sort(arr.begin() , arr.end()) ;
    int largest=1 , count=0 , lastsmaller=-1 ;
    for(int i=0 ; i<arr.size() ; i++){
        if(arr[i]-1==lastsmaller){
           lastsmaller=arr[i] ;
           count++ ;
        }
        else if(arr[i]-1!=lastsmaller){
           lastsmaller=arr[i] ;
           count=1 ;
       }
       largest=max(largest , count) ;
    }
    return largest ;
}
*/

//TC --> O(n) if set take O(1) time 
int longest_consecutive_sequence(vector<int> &arr){
    int largest=1 ;
    int n=arr.size() ;
    if(n==0) return 0 ;
    unordered_set<int> st ;
    for(int i=0 ; i<arr.size() ; i++){
        st.insert(arr[i]) ;
    }
    for(auto i : st){
        if(st.find(i-1)==st.end()){
            int count=1 ;
            int x=i ;
            while(st.find(x+1)!=st.end()){
                count++ ;
                x=x+1 ;
            }
            largest=max(largest , count) ;
        }
    }
    return largest ;
}

 
int main(){
vector<int> arr={102 , 4 , 100 , 8 , 103 , 3 , 2 , 101 , 7} ;
cout<<longest_consecutive_sequence(arr) ;
return 0 ;
}