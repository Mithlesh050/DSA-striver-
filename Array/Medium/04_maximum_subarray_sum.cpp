#include<bits/stdc++.h>
using namespace std ;

//kadane's algo
// int maximum_subarray_sum(vector<int> & arr){
//     int max=INT_MIN , sum=0 ;
//     for(int i=0 ; i<arr.size() ; i++){
//         sum+=arr[i] ;
//         if(max<sum){
//             max=sum ;
//         }
//         if(sum<0) sum=0 ;
//     }
//     return max ;
// }

vector<int> maximum_subarray_sum(vector<int> & arr){
    int max=INT_MIN , sum=0  , start=-1 , end=-1;
    vector<int> ans ;
    for(int i=0 ; i<arr.size() ; i++){
        if(sum==0) start=i ;
        sum+=arr[i] ;
        if(max<sum){
            max=sum ;
            end=i ;
        }
        if(sum<0) sum=0 ;
    }
    ans.push_back(start) ;
    ans.push_back(end) ;
    ans.push_back(max) ;
    return ans ;
}

int main(){
vector<int> arr={-2 , -3 , 4 , -1 , -2 , 1 , 5 , -3} ;
// cout<<maximum_subarray_sum(arr) ;
vector<int> ans=maximum_subarray_sum(arr) ;
cout<<"Maximum sum is "<<ans[2]<<endl ;
cout<<"Subarray is {" ;
for(int i=ans[0] ; i<=ans[1] ; i++)
cout<<arr[i]<<" , ";
cout<<"}" ;
return 0 ;
}