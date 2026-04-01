#include<bits/stdc++.h>
using namespace std ;

//TC --> O(n^3)
vector<vector<int>> four_sum(vector<int> &arr , int target){
    sort(arr.begin() , arr.end()) ;
    vector<vector<int>> ans ;
    for(int i=0 ; i<arr.size() ; i++){
        if(i>0 && arr[i]==arr[i-1]) continue; 
        for(int j=i+1 ; j<arr.size() ; j++){
            if(j!=i+1 && arr[j]==arr[j-1]) continue;
            int k=j+1 , l=arr.size()-1 ;
            while(k<l){
                int sum=arr[i]+arr[j]+arr[k]+arr[l] ;
                if(sum<target) k++ ;
                else if(sum>target) l-- ;
                else{
                    vector<int> temp={arr[i] , arr[j] , arr[k] , arr[l]} ;
                    ans.push_back(temp) ;
                    k++ ;
                    l-- ;
                    while(k<l && arr[k]==arr[k-1]) k++ ;
                    while(k<l && arr[l]==arr[l+1]) l-- ;
                }
            }
        }
    }
    return ans ;
}
 
int main(){
vector<int> arr={1 , 1 , 1 , 2 , 2 , 2 , 3 , 3 , 3 , 4 , 4 , 4 , 5 , 5} ;
int target=8 ;
vector<vector<int>> ans=four_sum(arr , target);
for(int i=0 ; i<ans.size() ; i++){
    cout<<"[" ;
    for(int j=0 ; j<ans[i].size() ; j++){
        cout<<ans[i][j]<<" ";
    }
    cout<<"] ";
}
return 0 ;
}