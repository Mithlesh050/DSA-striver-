#include<bits/stdc++.h>

using namespace std ;
 
int main(){
vector<int> arr={1 , 2 , 1 , 3 , 2 , 1} ;
int key=1 ;
map<int , int> mpp ;
for(int i=0  ; i<arr.size() ; i++){
    mpp[arr[i]]++ ;
}
for(auto ans : mpp)
cout<<ans.first<<" --> "<<ans.second<<endl ;
return 0 ;
}