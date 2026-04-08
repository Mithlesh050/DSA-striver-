#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;
 
int main(){
int n=5 ;

// for(int i=0 ; i<n ; i++){
//     for(int k=0 ; k<n-i-1 ; k++)
//         cout<<" " ;
//     for(int j=0 ; j<2*i+1 ; j++)
//     cout<<"*" ;
//     cout<<endl ;
// }

// for(int i=0 ; i<n ; i++){
//     for(int k=0 ; k<i ; k++)
//         cout<<" " ;
//     for(int j=0 ; j<2*n-2*i-1 ; j++)
//     cout<<"*" ;
//     cout<<endl ;
// }
int j ;
for(int i=0 ; i<n ; i++){
    int count=0 ;
    for(j=0 ; j<n-i-1 ; j++){
        cout<<" ";
    }
    for(int k=j ; k<n ; k++){
        cout<<char('A'+count++);
    }
    for(j=i-1 ; j>=0 ; j--){
        cout<<char('A'+j) ;
    }
    cout<<endl ;
}

return 0 ;
}