#include<bits/stdc++.h>
using namespace std ;
 
string infixToPrefix(string &s){
    string ans="" ;
    reverse(s.begin() , s.end()) ;
    stack<char> st ;
    unordered_map<char , int> mp ;
    mp['+']=1 ; mp['-']=1 ;
    mp['*']=2 ; mp['/']=2 ;
    mp['^']=3 ;
    int i=0 ;
    while(i<s.length()){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9'))
        ans+=s[i] ;
        else if(s[i]==')') st.push(s[i]) ;
        else if(s[i]=='('){
            while(!st.empty() && st.top()!=')'){
                ans+=st.top() ;
                st.pop() ;
            }
            st.pop() ;
        }
        else{
            if(!st.empty() && st.top()!=')' && mp[s[i]]<mp[st.top()]){
                ans+=st.top() ;
                st.pop() ;
            }
            st.push(s[i]) ;
        }
        i++ ;
    }
    while(!st.empty()){
        ans+=st.top() ;
        st.pop() ;
    }
    reverse(ans.begin() , ans.end()) ;
    return ans ;
}

int main(){
string s="(A+B)*C-D+E" ;
string ans=infixToPrefix(s) ;
cout<<ans ;
return 0 ;
}