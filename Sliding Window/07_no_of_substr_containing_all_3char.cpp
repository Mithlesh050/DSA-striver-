#include<bits/stdc++.h>
using namespace std ;
 

// TC --> O(n^2) && SC --> O(3) ;
/*
int numberOfSubstrings(string s) {
        int ans=0 ;
        for(int i=0 ; i<s.length() ; i++){
              set<char> st ;
              for(int j=i ; j<s.length() ; j++){
                st.insert(s[j]) ;
                if(st.size()==3) ans++ ;
              }
        }
        return ans ;
    }
*/

// TC --> O(2n)
/*
int numberOfSubstrings(string s) {
        int ans=0 ;
        int left=0 , right=0 ;
        unordered_map<char , int> mp ;
        while(right<s.length()){
            mp[s[right]]++ ;
            while(mp.size()==3){
                ans=ans+(s.length()-right) ;
                mp[s[left]]-- ;
                if(mp[s[left]]==0) mp.erase(s[left]) ;
                left++ ;
            }
            right++ ;
        }
        return ans ;
    }
*/

// TC --> O(n)
int numberOfSubstrings(string s) {
        int lastseen[3]={-1 , -1 , -1} ;
        int ans=0 , i=0;
        while(i<s.length()){
            lastseen[s[i]-'a']=i ;
            if(lastseen[0]!=-1 && lastseen[1]!=-1 && lastseen[2]!=-1){
                ans=ans+min(min(lastseen[0] , lastseen[1]) , lastseen[2])+1 ;
            }
            i++ ;
        }
     return ans ;
    }

int main(){
string s="abcabc" ;
cout<<numberOfSubstrings(s) ;
return 0 ;
}