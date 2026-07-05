#include<bits/stdc++.h>
using namespace std ;

class Solution {
  private :
    void f(int i , string &str , vector<string> &ans , string &s , int n){
        if(i==n){
            ans.push_back(str) ;
            return ;
        }
        str.push_back(s[i]) ;
        f(i+1 , str , ans , s , n) ;
        str.pop_back() ;
        f(i+1 , str , ans , s , n) ;
    }
  public:
    vector<string> powerSet(string &s) {
        vector<string> ans ;
        string str ;
        int n=s.length() ;
        f(0 , str , ans , s , n) ;
        sort(ans.begin() , ans.end()) ;
        return ans ;
    }
};

int main(){
Solution s ;
string str="abc" ;
vector<string> ans=s.powerSet(str) ;
for(auto it : ans) cout<<"'"<<it<<"'"<<" " ;
return 0 ;
}