#include<bits/stdc++.h>
using namespace std ;

// swapping two numbers
void swap_num(int *n1 , int *n2){
    *n1 = *n1 ^ *n2 ;
    *n2 = *n1 ^ *n2 ;
    *n1 = *n1 ^ *n2 ;
}

// check i'th bit is set or not
bool ithBitSetorNot(int n , int i){
    int temp=1<<i-1 ;
    if(n&temp) return true ;
    return false ;
}

// set the i'th bit
int set_ith_bit(int n , int i){
    return n | (1<<i-1) ;
}

// clear the i'th bit
int clearBit(int n , int i){
    int temp=~(1<<i-1) ;
    return n&temp ;
}

// toggle the i'th bit
int toggleBit(int n , int i){
    int temp=1<<i-1 ;
    return n^temp ;
}

// remove the last set bit (rightmost)
int removeBit(int n){
    return n&(n-1) ;
}

// check power of two
bool checkPowerOf2(int n){
    if(n&(n-1)) return false ;
    return true ;
}

// count number of set bits
int countBits(int n){
    int ans=0 ;
    while(n){
        n=n&n-1 ;
        ans++ ;
    }
    return ans ;
}

int main(){
int a = 5 , b=6 ;
// swap_num(&a , &b) ;
// cout<<"a = "<<a<<"  and  b ="<<b<<endl ;
// cout<<set_ith_bit(11 , 3) ;
// cout<<ithBitSetorNot(13 , 3) ;
// cout<<clearBit(13 , 3) ;
// cout<<toggleBit(13 , 3) ;
// cout<<removeBit(13) ;
// cout<<checkPowerOf2(13) ;
cout<<countBits(13) ;
return 0 ;
}