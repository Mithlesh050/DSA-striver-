#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;

int main(){
    int n=10 ;
    
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<i ; j++)
            cout<<"*" ;
        for(int k=0 ; k<2*n-2*i ; k++)
            cout<<" ";
        for(int j=0 ; j<i ; j++)
            cout<<"*" ;
        cout<<endl ;
    }

for(int i=0 ; i< n ; i++){
    for(int j=0 ; j<n-i ; j++)
    cout<<"*" ;
    for(int j=0 ; j<2*i ; j++)
    cout<<" ";
    for(int j=0 ; j<n-i ; j++)
    cout<<"*";
    if(i<n-1)
    cout<<endl ;
}

return 0 ;
}