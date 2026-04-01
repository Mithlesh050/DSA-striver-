#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;
 
int main(){
int n=36 ;
// for(int i=1 ; i<=n/2 ; i++){
//     if(n%i==0) cout<<i<<" , " ;
// }
// cout<<n ;
for(int i=1 ; i*i<=n ; i++){
    if(n%i==0){
        cout<<i<<" , " ;
        if(n/i!=i) cout<<n/i<<" , ";
    }
}
return 0 ;
}