#include<bits/stdc++.h>
using namespace std ;
 
// TC --> O(n^2) ;
/*
int maxi_product_subarray(vector<int> & arr){
    int maxi=-1 ;
    for(int i=0 ; i<arr.size() ; i++){
        int product=1 ;
        for(int j=i ; j<arr.size() ; j++){
            product=product*arr[j] ;
            if(maxi<product) maxi=product ;  
        }
    }
    return maxi ;
}
*/

int maxi_product_subarray(vector<int> & arr){
    int n=arr.size();
    int maxi=INT_MIN , prepro=1 , suffpro=1;
    for(int i=0 ; i<n ; i++){
        if(arr[i]==0) prepro=1 ;
        else prepro=prepro*arr[i] ;
        if(arr[n-i-1]==0) suffpro=1 ;
        else suffpro=suffpro*arr[n-i-1] ;
        maxi=max(maxi , max(prepro , suffpro)) ;
    }
    return maxi ;
}

int main(){
vector<int> arr={2 , 3 , -2 , 4} ;
cout<<maxi_product_subarray(arr) ;
return 0 ;
}