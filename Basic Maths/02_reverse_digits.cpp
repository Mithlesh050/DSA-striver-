#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;
 
int main(){
int n=12345 ;
int ans=0 ;
while(n){
    ans=ans*10+n%10 ;
    n=n/10 ;
}
cout<<ans ;
return 0 ;
}