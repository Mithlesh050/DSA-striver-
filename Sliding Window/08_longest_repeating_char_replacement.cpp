#include<bits/stdc++.h>
using namespace std ;

// TC --> O(n^2) 
/*
int characterReplacement(string s, int k) {
        int ans=0 ;
        for(int i=0 ; i<s.length() ; i++){
            int arr[26]={0} , maxfreq=0  ;
            for(int j=i ; j<s.length() ; j++){
                 arr[s[j]-'A']++ ;
                 maxfreq=max(maxfreq , arr[s[j]-'A']) ;
                 int change=(j-i+1)-maxfreq ;
                 if(change<=k)
                 ans=max(ans , j-i+1) ;
                 else break ;
            }
        }
        return ans ;
    }
*/

// TC --> O(2n)
/*
 int characterReplacement(string s, int k) {
        int ans=0 , maxfreq=0 , left=0 , right=0 ;
        int arr[26]={0} ;
        while(right<s.length()){
             arr[s[right]-'A']++ ;
             maxfreq=max(maxfreq , arr[s[right]-'A']) ;
             while(right-left+1-maxfreq>k){
                arr[s[left]-'A']-- ;
                left++ ;
             }
             ans=max(ans , right-left+1) ;
             right++ ;
        }  
        return ans ;
    }
*/

// TC --> O(n)
 int characterReplacement(string s, int k) {
        int ans=0 , maxfreq=0 , left=0 , right=0 ;
        int arr[26]={0} ;
        while(right<s.length()){
             arr[s[right]-'A']++ ;
             maxfreq=max(maxfreq , arr[s[right]-'A']) ;
             if(right-left+1-maxfreq>k){
                arr[s[left]-'A']-- ;
                left++ ;
             }
             ans=max(ans , right-left+1) ;
             right++ ;
        }  
        return ans ;
    }

int main(){
string s="AABABBA" ;
int k=1 ;
cout<<characterReplacement(s , k) ;
return 0 ;
}