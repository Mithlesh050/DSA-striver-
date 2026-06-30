#include<bits/stdc++.h>
using namespace std ;
 
string postToInfix(string &exp) {
        stack<string> st ;
        int i=0 ;
        while(i<exp.length()){
            if((exp[i]>='a' && exp[i]<='z') || (exp[i]>='A' && exp[i]<='Z') || (exp[i]>='0' && exp[i]<='9')){
                string temp="" ;
                temp+=exp[i] ;
                st.push(temp) ;
            }
            else{
                string temp="" ;
                string sec=st.top() ;
                st.pop() ;
                string first=st.top() ;
                st.pop() ;
                temp.append('('+first+exp[i]+sec+')') ;
                st.push(temp) ;
            }
            i++ ;
        }
       return st.top() ; 
    }

int main(){
string s="ab*c+";
string ans=postToInfix(s) ;
cout<<ans ;
return 0 ;
}