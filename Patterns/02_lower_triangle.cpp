#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;
 
int main(){
int n=10 ;
// for(int i=0 ; i<n ; i++){
//     for(int j=0 ; j<i ; j++){
//         cout<<" * " ;
//     }
//     cout<<"\n" ;
// }

// cout<<endl ;

// for(int i=0 ; i<n ; i++){
//     for(int j=0 ; j<=i ; j++){
//         cout<<(j+i+1)%2 ;
//     }
//     cout<<"\n" ;
// }

// cout<<endl ;

// int count=1 ;
// for(int i=0 ; i<n ; i++){
//     for(int j=0 ;j<i ; j++ )
//         cout<<count++<<" " ;
//         cout<<endl ;
// }

for(int i=0 ; i<n ; i++){
    for(int j=0 ; j<i ; j++){
        cout<<char('A'+j)<<" " ;
    }
    cout<<endl ;
}
return 0 ;
}