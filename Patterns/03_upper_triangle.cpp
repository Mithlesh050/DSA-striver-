#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;
 
int main(){
int n=10 ;
// for(int i=0 ; i<n ; i++){
//     for(int j=0 ; j<n-i ; j++){
//         cout<<" * " ;
//     }
//     cout<<endl ;
// }

for(int i=0 ; i<n ; i++){
    for(int j=0 ; j<n-i ; j++){
        cout<<char('A'+j)<<" " ;
    }
    cout<<endl ;
}

for(int i=0 ; i<n ; i++){
    for(int j=0 ; j<n-i ; j++){
        cout<<char('A'+i)<<" " ;
    }
    cout<<endl ;
}



return 0 ;
}