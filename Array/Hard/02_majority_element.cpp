#include<bits/stdc++.h>
using namespace std ;
 
//TC --> O(nlogn) for ordered map &&  O(n) for unordered map 
/*
vector<int> majority_element(vector<int> &arr){
    vector<int> ans ;
    int mx=arr.size()/3 ;
    unordered_map<int , int> mp ;
    for(int i=0 ; i<arr.size() ; i++){
         mp[arr[i]]++ ;
         if(mp[arr[i]]==mx+1){
            ans.push_back(arr[i]) ;
         }
    }
    return ans ;
}
*/

//without space TC--> O(n)
vector<int> majority_element(vector<int> &arr){
    vector<int> ans ;
    int count1=0 , count2=0 , ele1=0 , ele2=0 ;
    for(int i=0 ; i<arr.size() ; i++){
        if(count1==0 && arr[i]!=ele2){
            count1++ ;
            ele1=arr[i] ;
        }
        else if(count2==0 && arr[i]!=ele1){
            count2++ ;
            ele2=arr[i] ;
        }
        else if(arr[i]==ele1)
        count1++ ;
        else if(arr[i]==ele2)
        count2++ ;
        else{
            count1-- ;
            count2-- ;
        }
    }
    count1=0 , count2=0 ;
    for(int i=0 ; i<arr.size() ; i++){
        if(arr[i]==ele1) count1++ ;
        else if(arr[i]==ele2) count2++ ;
    }
    int mx=arr.size()/3 ;
    if(count1>mx) ans.push_back(ele1) ;
    if(count2>mx) ans.push_back(ele2) ;
    return ans ;
}


int main(){
vector<int> arr={1 , 1 , 1 , 3 ,  2 , 2 , 2 , 1};
vector<int> ans = majority_element(arr) ;
for(auto i: ans){
    cout<<i<<" " ;
}
return 0 ;
}