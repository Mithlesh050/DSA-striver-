#include<bits/stdc++.h>
using namespace std ;
 
int main(){
string s="zabacbdefaz" ;
map<char , int> mpp ;
for(int i=0 ; i<s.length() ; i++){
    mpp[s[i]]++ ;
}
for(auto ans: mpp)
cout<<ans.first<<" --> "<<ans.second<<endl ;
return 0 ;
}