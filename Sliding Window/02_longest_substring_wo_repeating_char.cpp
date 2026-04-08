#include<bits/stdc++.h>
using namespace std ;
 

// TC --> O(n^2) & SC --> O(256)
/*
int lengthOfLongestSubstring(string s) {
        int ans=0 , n=s.length() ;
        for(int i=0 ; i<n ; i++){
            string substr="" ;
            int arr[256]={0} ;
            for(int j=i ; j<n ; j++){
                if(arr[s[j]]>0) break ;
                substr=substr+s[j] ;
                arr[s[j]]++ ;
            }
            if(ans<substr.length()) ans=substr.length() ;
        }
        return ans ;
    }
*/

// TC --> O(n) & SC --> O(n)
int lengthOfLongestSubstring(string s) {
        int ans = 0, n = s.length();
        int left = 0, right = 0;
        unordered_map<char, int> mp;
        while (right < n) {
            char temp = s[right];
            if (mp.find(temp) != mp.end()) {
                if (mp[temp] >= left)
                    left = mp[temp] + 1;
            }
            ans = max(ans, right - left + 1);
            mp[temp] = right;
            right++;
        }
        return ans;
    }

int main(){
string str="abcabcbb" ;
cout<<lengthOfLongestSubstring(str) ;
return 0 ;
}