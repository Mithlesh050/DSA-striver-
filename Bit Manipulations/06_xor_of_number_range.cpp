#include<bits/stdc++.h>
using namespace std ;

class Solution {
    private :
    int f(int n){
        if(n%4==1) return 1 ;
        else if(n%4==2) return n+1 ;
        else if(n%4==3) return 0 ;
        else return n ;
    }
  public:
    int findXOR(int l, int r) {
        int i=f(l-1) , j=f(r) ;
        return i^j ;
    }
};

int main(){
Solution s ;
int l=4 , r=8 ;
cout<<s.findXOR(l , r) ;
return 0 ;
}