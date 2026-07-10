#include<bits/stdc++.h>
using namespace std ;

class Solution {
private :
    bool isValidposi(int row , int col , vector<string> &board , int n){
        int i=row , j=col ;
        while(i>=0 && j>=0){
            if(board[i][j]=='Q') return false ;
            i-- ;
            j-- ;
        }
        i=row  ;
        j=col ;
        while(j>=0){
            if(board[i][j]=='Q') return false ;
            j-- ;
        }
        j=col ;
        while(i<n && j>=0){
            if(board[i][j]=='Q') return false ;
            i++ ;
            j-- ;
        }
        return true ;
    }

    void f(int col , vector<string> &board , vector<vector<string>> &ans , int n){
        if(col==n){
            ans.push_back(board) ;
            return ;
        }
        for(int row=0 ; row<n ; row++){
            if(isValidposi(row , col , board , n)){
                board[row][col]='Q' ;
                f(col+1 , board , ans , n) ;
                board[row][col]='.' ;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans ;
        vector<string> board(n) ;
        string str="" ;
        for(int i=0 ; i<n ; i++) str+='.' ;
        for(int i=0 ; i<n ; i++) board[i]=str ;
        f(0 , board , ans , n) ;
        return ans ;
    }
};

int main(){
Solution s ;
int n ;
cin>>n ;
vector<vector<string>> ans=s.solveNQueens(n) ;
for(int i=0 ; i<ans.size() ; i++){
    for(int j=0 ; j<ans[i].size() ; j++){
        for(int k=0 ; k<n ; k++){
            cout<<ans[i][j][k]<<" " ;
        }
        cout<<endl ;
    }
    cout<<endl<<endl ;
}
return 0 ;
}