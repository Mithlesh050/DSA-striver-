#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;

void printLinear(int n){
    if(n==0) return ;
    printLinear(n-1);
    cout<<n<<" " ;
}
 
int main(){
int n=10 ;
// cout<<"Enter n : " ;
// cin>>n ;

cout<<"Print number from 1 to "<<n<<" " ;
printLinear(n) ;
return 0 ;
}