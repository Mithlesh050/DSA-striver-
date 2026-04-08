#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;
 
int main(){
vector<int> v={1 , 2 , 3 , 2 , 1 , 2 , 5 ,2} ;
int key=2 ;
int n= *max_element(v.begin() , v.end());
int arr[n+1]={0} ;
for(int i=0 ; i<v.size() ; i++){
    arr[v[i]]++ ;
}
cout<<arr[key] ;
return 0 ;
}