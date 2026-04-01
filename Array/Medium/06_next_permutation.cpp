#include<bits/stdc++.h>
using namespace std ;
//TC--> O(n!*n)
// void next_permut(vector<int> & arr){
//     next_permutation(arr.begin() , arr.end()) ;
// }

//TC--> O(3n) 
 void next_permut(vector<int> & arr){
    int index=-1 ;
    for(int i=arr.size()-2 ; i>=0 ; i--){
        if(arr[i]<arr[i+1]) {
            index=i ;
            break;
        }
    }
    if(index==-1){
        reverse(arr.begin() , arr.end()) ;
    }
    else{
        for(int i=arr.size()-1 ; i>index ; i--){
             if(arr[i]>arr[index]){
            swap(arr[i] , arr[index]) ;
            break;
            }
        }
        reverse(arr.begin()+index+1 , arr.end());
    }

}
 
int main(){
vector<int> arr={2 , 4 , 1 , 7 , 5 , 0} ;
next_permut(arr) ;
for(auto i: arr)
cout<<i<<" " ;
return 0 ;
}