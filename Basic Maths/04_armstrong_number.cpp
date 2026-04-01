#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;

int power(int n , int x){
    int val=1 ;
    while(x){
       val=val*n ;
       x-- ; 
    }
    return val ;
}
 
int main(){
int n=371 ;
int temp=n , cal=0 , digit=0 ;
while(temp){digit++ ; temp=temp/10 ;}
temp=n ;
while(temp){
    int digi=temp%10 ;
    cal=cal + power(digi , digit) ;
    temp=temp/10 ;
}
if(cal==n) cout<<"Armstrong" ;
else cout<<"Not Armstrong" ;
return 0 ;
}