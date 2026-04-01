#include<bits/stdc++.h>
using namespace std ;
 
int main(){
int n=7 ;
int arr[n]={1 , 6 , 3 , 8 , 4 , 12 , 10} ;

// int largest=-1 ;
// int slargest=-1 ;
// for(int i=0 ; i<n ; i++)
//     if(largest<arr[i]) 
//     largest=arr[i] ;

// for(int i=0 ; i<n ; i++){
//     if(slargest<arr[i] && arr[i]!=largest)
//     slargest=arr[i] ;
// }

//optimal solution

int largest=arr[0]  , slargest=-1 ;
for(int i=1 ; i<n ; i++){
    if(largest<arr[i]){
        slargest=largest;
        largest=arr[i] ;
    }
    else if(slargest<arr[i]){
        slargest=arr[i] ;
    }
    
}

cout<<"Second largest element in given array is "<<slargest ;

return 0 ;
}