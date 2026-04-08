#include<bits/stdc++.h>
using namespace std ;
 
int main(){
string s="zabacbdefaz" ;
map<char , int> mpp ;
for(int i=0 ; i<s.length() ; i++){
    mpp[s[i]]++ ;
}
int max=0 , min=s.length()+1 ;
char e1 , e2;
for(auto ans: mpp){
    if(ans.second<min){ min=ans.second ; e1=ans.first ;}
    if(ans.second>max){ max=ans.second ; e2=ans.first; }
}
cout<<"Maximum frequency "<<char(e2)<<" --> "<<max<<endl ;
cout<<"Minimum frequency "<<char(e1)<<" --> "<<min ;
return 0 ;
}