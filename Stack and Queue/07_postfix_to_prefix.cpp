#include<bits/stdc++.h>
using namespace std ;

string postToPre(string post_exp) {
        stack<string> st ;
        int i=0 ; 
        while(i<post_exp.length()){
            if((post_exp[i]>='a' && post_exp[i]<='z') || (post_exp[i]>='A' && post_exp[i]<='Z')){
                string temp="" ;
                temp+=post_exp[i] ;
                st.push(temp) ;
            }
            else{
                string temp="" ;
                string sec=st.top() ;
                st.pop() ;
                string first=st.top() ;
                st.pop() ;
                temp+=post_exp[i]+first+sec ;
                st.push(temp) ;
            }
            i++ ;
        }
        return st.top() ;
    }

int main(){
string s="ABC/-AK/L-*" ;
string ans=postToPre(s) ;
cout<<ans ;
return 0 ;
}