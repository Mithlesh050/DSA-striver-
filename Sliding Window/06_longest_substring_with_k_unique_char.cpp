#include<bits/stdc++.h>
using namespace std ;
 
// TC --> O(n^2) && SC --> O(k) ;
/*
int longestKSubstr(string &s, int k) {
        int ans=-1 ;
        for(int i=0 ; i<s.length() ; i++){
            set<char> st ;
            for(int j=i ; j<s.length() ; j++){
                st.insert(s[j]) ;
                if(st.size()>k)
                break ;
                if(st.size()==k)
                ans=max(ans , j-i+1) ;
            }
        }
        return ans ;
    }
*/
// TC --> O(2n)
/*
int longestKSubstr(string &s, int k) {
        int ans=-1 , left=0 , right=0 ;
        unordered_map<char , int> mp ;
        while(right<s.length()){
            mp[s[right]]++ ;
            while(mp.size()>k){
                mp[s[left]]-- ;
                if(mp[s[left]]==0)
                mp.erase(s[left]) ;
                left++ ;
            }
            if(mp.size()==k)
            ans=max(ans , right-left+1) ;
            right++ ;
        }
        return ans ;
    }
*/

// TC --> O(n)
int longestKSubstr(string &s, int k) {
        int ans=-1 , left=0 , right=0 ;
        unordered_map<char , int> mp ;
        while(right<s.length()){
            mp[s[right]]++ ;
            if(mp.size()>k){
                mp[s[left]]-- ;
                if(mp[s[left]]==0)
                mp.erase(s[left]) ;
                left++ ;
                right++ ;
            }
            else{
                if(mp.size()==k)
                ans=max(ans , right-left+1) ;
                right++ ;
            }
        }
        return ans ;
    }


int main(){
string s="aabacbebebe" ;
int k=3 ;
cout<<longestKSubstr(s , k) ;
return 0 ;
}