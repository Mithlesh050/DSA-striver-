#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor) return 1 ;
        bool sign=true ;
        if(dividend< 0 && divisor>0) sign=false ;
        else if(dividend>0 && divisor<0) sign=false ;
        long n = labs((long)dividend);
        long d = labs((long)divisor);
        long  ans=0 ;
        while(n>=d){
            int count=0 ;
            while(n>=(d<<(count+1))){
                count++ ;
            }
            ans=ans+(1L<<count) ;
            n-=(d<<count) ;
        }
        if (sign && ans > INT_MAX) return INT_MAX;
        if (!sign && -ans < INT_MIN) return INT_MIN;
        return sign?ans : -ans ;
    }
};

int main(){
Solution s ;
int dividend=10 , divisor=3 ;
cout<<s.divide(dividend , divisor) ;
return 0 ;
}