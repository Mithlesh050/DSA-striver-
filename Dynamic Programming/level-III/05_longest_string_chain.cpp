#include<bits/stdc++.h>
using namespace std ;

class Solution {
private : 
    bool check(string &s1 , string &s2){
        if(s1.size()!=s2.size()+1) return false ;
        int i=0 ,  j=0 ;
        while(i<s1.size()){
            if(s1[i]==s2[j]){
                i++ ; 
                j++ ;
            }
            else{
                i++ ;
            }
        }
        if(s1.size()==i && s2.size()==j) return true ;
        return false ;
    }

    static bool comp(string &s1 , string &s2){
        return s1.size()<s2.size() ;
    }

public:
    int longestStrChain(vector<string>& words) {
        int n=words.size() , ans=1 ;
        sort(words.begin() , words.end() , comp) ;
        vector<int> dp(n , 1);
        for(int i=1 ; i<n ; i++){
            for(int j=0 ; j<i ; j++){
                if(check(words[i] , words[j]) && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1 ;
                }
            }
            ans=max(ans , dp[i]) ;
        }
        return ans ;
    }
};

int main(){
Solution s ;
vector<string> words={"xbc","pcxbcf","xb","cxbc","pcxbc"} ;
cout<<s.longestStrChain(words) ;
return 0 ;
}