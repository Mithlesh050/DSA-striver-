#include<bits/stdc++.h>
using namespace std ;

class Solution {

  public:
    int minOperations(string &s1, string &s2) {
       int n=s1.length() , m=s2.length() ;
       vector<int> prev(m+1 , 0) , curr(m+1 , 0) ;
       for(int i=1 ; i<=n ; i++){
           for(int j=1 ; j<=m ; j++){
               if(s1[i-1]==s2[j-1]) curr[j]=1+prev[j-1] ;
               else curr[j]=max(prev[j] , curr[j-1]) ;
           }
           prev=curr ;
       }
       return n+m-2*prev[m] ;
    }
};

int main(){
Solution s ;
string s1="heap" , s2="pea" ;
cout << s.minOperations(s1, s2);
return 0 ;
}