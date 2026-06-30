#include<bits/stdc++.h>
using namespace std ;
 
string removeKdigits(string num, int k) {
        if (k == 0)
            return num;
        if (k == num.length())
            return "0";
        string ans = "";
        stack<char> st;
        int i = 0;
        while(i<num.length()){
            while (!st.empty() && k && st.top() > num[i]) {
                st.pop();
                k--;
                if (k == 0)
                    break;
            }
            if(st.empty() && num[i]=='0'){
                i++ ;
                continue ;
            }
            st.push(num[i]);
            i++;
        }
        while(!st.empty() && k){
            st.pop() ;
            k-- ;
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        if(ans.size()==0) return "0" ;
        reverse(ans.begin() , ans.end()) ;
        return ans ;
    }

int main(){
string s="1432219" ;
int k=3 ;
cout<<removeKdigits(s , k) ;
return 0 ;
}