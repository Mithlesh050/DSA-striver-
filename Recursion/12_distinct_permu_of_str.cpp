#include<bits/stdc++.h>
using namespace std ;

/* class Solution {
  private :
    void f(string &temp , vector<int> &freq , set<string> &st , string &s){
        if(temp.size()==s.size()){
            st.insert(temp) ;
            return ;
        }
        for(int i=0 ; i<s.size() ; i++){
            if(!freq[i]){
                temp.push_back(s[i]) ;
                freq[i]=1 ;
                f(temp , freq , st , s) ;
                freq[i]=0 ;
                temp.pop_back() ;
            }
        }
    }
  public:
    vector<string> findPermutation(string &s) {
        vector<string> ans ;
        string temp ;
        vector<int> freq(s.size() , 0) ;
        set<string> st ;
        f(temp , freq , st , s) ;
        for(auto it : st) ans.push_back(it) ;
        return ans ;
    }
}; */

class Solution {
  private :
    void f(int ind , set<string> &st , string &s){
        if(ind==s.size()){
           st.insert(s) ;
           return ; 
        }
        for(int i=ind ; i<s.size() ; i++){
            swap(s[ind] , s[i]) ;
            f(ind+1 , st , s) ;
            swap(s[ind] , s[i]) ;
        }
    }
  public:
    vector<string> findPermutation(string &s) {
        vector<string> ans ;
        set<string> st ;
        f(0 , st , s) ;
        for(auto it : st) ans.push_back(it) ;
        return ans ;
    }
};


int main(){
Solution s ;
string str="ABC" ;
vector<string> ans=s.findPermutation(str) ;
for(auto it : ans) cout<<it<<" " ;
return 0 ;
}