#include<bits/stdc++.h>
using namespace std ;
 
//TC --> O(nlogn)
/*
vector<vector<int>> merge_overlapping_subintervals(vector<vector<int>> & arr){
    sort(arr.begin() , arr.end()) ;
    vector<vector<int>> ans ;
    int i=0 ;
    while(i<arr.size()){
        vector<int> temp ;
        temp.push_back(arr[i][0]);
        int j=i+1 ;
        int end=arr[i][1] ;
        while(j<arr.size() && arr[j][0]<=end){
            if(arr[j][1]>end) end=arr[j][1] ;
            j++ ;
        }
        temp.push_back(end) ;
        ans.push_back(temp) ;
        i=j ;
    }
    return ans ;
}
*/


vector<vector<int>> merge_overlapping_subintervals(vector<vector<int>> & arr){
    sort(arr.begin() , arr.end()) ;
    vector<vector<int>> ans ;
    for(int i=0 ; i<arr.size() ; i++){
        if(ans.empty() || arr[i][0]>ans.back()[1]){
            ans.push_back(arr[i]);
        }
        else{
            ans.back()[1]=max(ans.back()[1] , arr[i][1]) ;
        }
    }
    return ans ;
}


int main(){
vector<vector<int>> arr={{1 , 3},{2 , 6},{8 , 10},{15 , 18}} ;
vector<vector<int>> ans =merge_overlapping_subintervals(arr) ;
for(int i=0 ; i<ans.size() ; i++){
    cout<<"[" ;
    for(int j=0 ; j<2 ; j++){
        cout<<ans[i][j]<<" " ;
    }
    cout<<"] " ;
}
return 0 ;
}