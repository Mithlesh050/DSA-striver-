#include<bits/stdc++.h>
using namespace std ;

vector<vector<int>> subsets(vector<int> &arr){
    int n=arr.size() ;
    vector<vector<int>> ans ;
    for(int i=0 ; i<1<<n ; i++){
        vector<int> temp ;
        for(int j=0 ; j<n ; j++){
            if(i&(1<<j)) temp.push_back(arr[j]) ;
        }
        ans.push_back(temp) ;
    }
    return ans ;
}

int main(){
vector<int> arr={1 , 2 , 3} ;
vector<vector<int>> ans=subsets(arr) ;
for(int i=0 ; i<ans.size() ; i++){
    cout<<"[" ;
    for(int j=0 ; j<ans[i].size() ; j++){
        if(j<ans[i].size()-1)
        cout<<ans[i][j]<<" , " ;
        else cout<<ans[i][j] ;
    }
    cout<<"]  " ;
}
return 0 ;
}