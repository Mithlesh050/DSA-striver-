#include<bits/stdc++.h>
using namespace std ;
 
int main(){
int n=7 ;
int arr[n]={1 , 2 , 3 , 4 , 5 , 6 , 7} ;

// TC--> O(nlogn)
// set<int> st ;
// for(int i=0 ; i<n ; i++)
// st.insert(arr[i]) ;
// for(auto i : st)
// cout<<i<<" " ;

int i=0 ;
for(int j=i+1 ; j<n ; j++){
    if(arr[i]!=arr[j]){
       i++ ;
       arr[i]=arr[j];
    }
}

i++ ;
while(i<n){arr[i]=0 ; i++ ;}

for(int i=0 ; i<n ; i++)
cout<<arr[i]<<" " ;

return 0 ;
}