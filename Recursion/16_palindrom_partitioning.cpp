#include<bits/stdc++.h>
using namespace std ;

class Solution {
private :
    bool isPalindrom(string &s , int i , int j){
        while(i<j){
            if(s[i]!=s[j]) return false ;
            i++ ;
            j-- ;
        }
        return true ;
    }

    void f(int ind , vector<string> &temp , vector<vector<string>> &ans , string &s){
        if(ind==s.size()){
            ans.push_back(temp) ;
            return ;
        }
        for(int i=ind ; i<s.size() ; i++){
            if(isPalindrom(s , ind , i)){
                temp.push_back(s.substr(ind , i+1-ind)) ;
                f(i+1 , temp , ans , s) ;
                temp.pop_back() ;
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans ;
        vector<string> temp ;
        f(0 , temp , ans , s) ;
        return ans ;
    }
};

int main(){
Solution s ;
string str="aab" ;
vector<vector<string>> ans=s.partition(str) ;
for(int i=0 ; i<ans.size() ; i++){
    for(auto it : ans[i]) cout<<it<<" " ;
    cout<<endl ;
}
return 0 ;
}