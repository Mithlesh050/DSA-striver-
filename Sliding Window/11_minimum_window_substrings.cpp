#include<bits/stdc++.h>
using namespace std ;

// TC --> O(n^2)
/*
string minWindow(string s, string t) {
        int minlength=INT_MAX  , si=-1 ;
        for(int i=0 ; i<s.size() ; i++){
            int hash[257]={0} , count=0 ;
            for(int j=0 ; j<t.size() ; j++) hash[t[j]]++ ;
            for(int j=i ; j<s.size() ; j++){
                if(hash[s[j]]>0){
                count++ ;
                }
                hash[s[j]]-- ;
                if(count==t.size()){
                    if(minlength>j-i+1){
                       minlength=j-i+1 ;
                       si=i ;
                    }
                    break ;
                }  
            }
        }
        string ans=s.substr(si , minlength) ;
        return ans ;
    }
*/

// TC --> O(2n)
string minWindow(string s, string t) {
        int minlength=INT_MAX , sindex=-1 ;
        int left=0 , right=0 , count=0 ;
        int hash[256]={0} ;
        for(int i=0 ; i<t.size() ; i++) hash[t[i]]++ ;
        while(right<s.size()){
            if(hash[s[right]]>0) count++ ;
            hash[s[right]]-- ;
            while(count==t.size()){
                if(minlength>right-left+1){
                    minlength=right-left+1;
                    sindex=left ;
                }
                hash[s[left]]++ ;
                if(hash[s[left]]>0) count-- ;
                left++ ;
            }
            right++ ;
        }
        string ans="" ;
        if(sindex!=-1) ans=s.substr(sindex , minlength) ;
        return ans ;
    }

int main(){
string s="ADOBECODEBANC" ;
string t="ABC" ;
string ans=minWindow(s , t) ;
cout<<ans ;
return 0 ;
}