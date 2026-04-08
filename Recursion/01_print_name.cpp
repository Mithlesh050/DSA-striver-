#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;

void printName(string s , int n){
    if(n==0) return ;
    cout<<s<<endl ;
    printName(s , n-1);
}
 
int main(){
int n ;
cout<<"How many times you want to print your name : " ;
cin>> n ;
string s="Mithlesh Kumar Yadav";
printName(s , n);
return 0 ;
}