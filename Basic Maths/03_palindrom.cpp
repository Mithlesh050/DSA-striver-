#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;
 
int main(){
int n = 1233216 ;
int ans=0 , temp=n ;
while(n){
    ans=ans*10+n%10 ;
    n=n/10 ;
}
if(temp==ans) cout<<"Given number is palindrom" ;
else cout<<"Not palindrom" ;
return 0 ;
}