#include<bits/stdc++.h>
using namespace std ;

vector<int> leaders_in_array(vector<int> & arr){
    int n=arr.size()-1 ;
    vector<int> ans ;
    ans.push_back(arr[n]) ;
    int max=arr[n] ;
    for(int i=n-1 ; i>=0 ; i--){
        if(max<arr[i]){
            ans.push_back(arr[i]) ;
            max=arr[i] ;
        }
    }
    return ans ;
}

int main(){
vector<int> arr={10 , 22 , 12 , 3 , 0 , 6} ;
vector<int> ans=leaders_in_array(arr) ;
for(auto i: ans)
cout<<i<<" " ;
return 0 ;
}