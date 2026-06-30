#include<bits/stdc++.h>
using namespace std ;

string preToPost(string pre_exp) {
        stack<string> st ;
        int i=pre_exp.length()-1 ; 
        while(i>=0){
            if((pre_exp[i]>='a' && pre_exp[i]<='z') || (pre_exp[i]>='A' && pre_exp[i]<='Z')){
                string temp="" ;
                temp+=pre_exp[i] ;
                st.push(temp) ;
            }
            else{
                string temp="" ;
                string first=st.top() ;
                st.pop() ;
                string sec=st.top() ;
                st.pop() ;
                temp+=first+sec+pre_exp[i] ;
                st.push(temp) ;
            }
            i-- ;
        }
        return st.top() ;
    }

int main(){
string s="*-A/BC-/AKL" ;
string ans=preToPost(s) ;
cout<<ans ;
return 0 ;
}