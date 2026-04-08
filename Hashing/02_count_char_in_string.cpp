#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;
 
int main(){
string s="aababcadaez" ;
int hash[26]={0} ;
for(int i=0 ; i<s.length() ; i++){
    hash[s[i]%97]++ ;
}
char key='a'  ;
cout<<"Number of a in given string is "<<hash[key%97] ;
return 0 ;
}