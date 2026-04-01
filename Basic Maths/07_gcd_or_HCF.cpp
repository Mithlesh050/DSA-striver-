#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;
 
int main(){
int a=52 , b=10 ;
while(a>0 && b>0){
    if(a>b) a=a%b ;
    else b=b%a ;
}
if(a==0) cout<<"HCF = "<<b ;
else cout<<"HCF = "<<a ;
return 0 ;
}