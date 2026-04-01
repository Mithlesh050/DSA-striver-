#include<bits/stdc++.h>
using namespace std ;

int insert_position(vector<int> &arr , int key){
    int ans=arr.size() ;
    int low=0 , high=arr.size()-1 ;
    while(low<=high){
        int mid=(low+high)/2 ;
        if(arr[mid]<key) low=mid+1 ;
        else{
            ans=mid ;
            high=mid-1 ;
        }
    }
    return ans ;
}

int main(){
vector<int> arr={1 , 2 , 4 , 7} ;
int key=6 ;
cout<<"Insert Position : "<<insert_position(arr , key) ;
return 0 ;
}