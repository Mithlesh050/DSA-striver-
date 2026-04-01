#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;
 
int main(){
int n=12 ;
int count=2 ;
for(int i=2 ; i*i<=n ; i++){
    if(n%i==0){
        count++ ;
        break;
    }
}
if(n==1 || count>2) cout<<"Not Prime" ;
else cout<<"Prime" ;
return 0 ;
}