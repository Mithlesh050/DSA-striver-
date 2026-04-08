#include<bits/stdc++.h>
using namespace std ;

int consecutive_ones(vector<int> & arr){
    int ans=0 , left=0 , maxcount=0;
    for(int right=0 ; right<arr.size() ; right++){
        if(arr[right]==0){
            maxcount=0 ;
        }
        else{
            maxcount++ ;
            ans=max(ans , maxcount) ;
        }
    }
    return ans ;
}
 
int main(){
vector<int> arr={1 , 1 , 0 , 1 , 1 , 1} ;
cout<<consecutive_ones(arr) ;
return 0 ;
}