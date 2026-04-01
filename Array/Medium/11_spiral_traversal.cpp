#include<bits/stdc++.h>
using namespace std ;

vector<int> spiral_traversal(vector<vector<int>> &arr){
    vector<int> ans ;
    int left=0 , right=arr[0].size()-1 , top=0 , bottom=arr.size()-1 ;
    while(top<=bottom && left<=right){
        for(int i=left ; i<=right ; i++){
             ans.push_back(arr[top][i]);
        }
        top++ ;
        for(int i=top ; i<=bottom ; i++){
            ans.push_back(arr[i][right]) ;
        }
        right-- ;
        if(left<=right)
        for(int i=right ; i>=left ; i--){
            ans.push_back(arr[bottom][i]);
        }
        bottom-- ;
        if(top<=bottom)
        for(int i=bottom ; i>=top ; i--){
            ans.push_back(arr[i][left]) ;
        }
        left++ ;
    }
    return ans ;
}
 
int main(){
vector<vector<int>> arr={{1 , 2 , 3 , 4 } , 
                         {5 , 6 , 7 , 8 } , 
                         {9 , 10 , 11 , 12} ,
                         {13 , 14 , 15 , 16 }} ;

vector<int> ans=spiral_traversal(arr) ;
for(auto  i: ans) cout<<i<<" ";
return 0 ;
}