#include<bits/stdc++.h>
using namespace std ;
/* Pascal's Triangle
                   1
                1    1
              1    2    1
            1   3    3    1
          1   4   6    4     1
        1   5  10   10    5    1
      1   6  15   20   15   6    1

*/
 
//printing element

// int ncr(int r , int c){
//     int ans=1 ;
//     for(int i=0 ; i<c ; i++){
//          ans=ans*(r-i) ;
//          ans=ans/(i+1) ;
//     }
//     return ans ;
// }

//printing row 
void print_row(int r){
    int temp=1 ;
    for(int i=0 ; i<=r ; i++){
        // int temp=ncr(r-1 , i-1) ;   --> O(r*c)  ;
        cout<<temp<<"  " ;
        temp=(temp*(r-i))/(i+1) ;    // --> O(r) ;
    }
}

//printing triangle
void print_tringle(int row){
    for(int i=1 ; i<=row ; i++){
        print_row(i-1) ;
        cout<<endl ;
    }
}

int main(){
int row=7 , col=3 ;

// finding particular element if row ans column is given
// cout<<ncr(row-1 , col-1) ;

// printing whole row
// print_row(row-1) ;

//Printing whole triangel ;
print_tringle(row) ;

return 0 ;
}