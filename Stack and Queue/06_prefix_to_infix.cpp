#include<bits/stdc++.h>
using namespace std ;

string preToInfix(string exp) {
        stack<string> st ;
        int i=exp.length()-1 ;
        while(i>=0){
            if((exp[i]>='a' && exp[i]<='z') || (exp[i]>='A' && exp[i]<='Z')){
                string temp="" ;
                temp+=exp[i] ;
                st.push(temp) ;
            }
            else{
                string temp="" ;
                string first=st.top() ;
                st.pop() ;
                string sec=st.top() ;
                st.pop() ;
                temp='('+first+exp[i]+sec+')' ;
                st.push(temp) ;
            }
            i-- ;
        }
       return st.top() ; 
    }

int main(){
string s="*-A/BC-/AKL" ;
string ans=preToInfix(s) ;
cout<<ans ;
return 0 ;
}