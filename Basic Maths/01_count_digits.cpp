#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;
 
int main(){
int n=2345 ;
int count=0 ;
while(n){
    count++ ;
    n=n/10 ;
}
cout<<count ;
return 0 ;
}