#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int temp=start^goal ;
        int count=0 ;
        while(temp){
            temp=temp&temp-1 ;
            count++ ;
        }
        return count ;
    }
};

int main(){
Solution s ;
int start=10 , goal=7 ;
cout<<s.minBitFlips(start , goal) ;
return 0 ;
}