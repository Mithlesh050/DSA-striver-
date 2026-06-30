#include<bits/stdc++.h>
using namespace std ;
 

string infixToPostfix(string& s) {
        map<char , int> mp ;
        mp['+']=1 ; mp['-']=1 ;
        mp['*']=2 ; mp['/']=2 ;
        mp['^']=3 ;
        stack<char> st ;
        string ans="" ;
        int i=0 ;
        while(i<s.length()){
            if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')){
                ans+=s[i] ;
            }
            else if(s[i]=='(') st.push(s[i]) ;
            else if(s[i]==')'){
                while(!st.empty() && st.top()!='('){
                    ans+=st.top() ;
                    st.pop() ;
                }
                st.pop() ;
            }
            else{
                while(!st.empty() && st.top()!='(' && mp[s[i]]<=mp[st.top()]){
                    if(mp[s[i]]==mp[st.top()] && s[i]=='^') break ;
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
        return ans ;
    }

int main(){
string s="a*(b+c)/d" ;
string ans=infixToPostfix(s) ;
cout<<ans ;
return 0 ;
}