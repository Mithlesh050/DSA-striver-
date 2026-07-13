#include<bits/stdc++.h>
using namespace std ;

class Solution {
  private:
    void f(int i , int j , vector<vector<int>> &maze , string s , vector<vector<int>> &vis , vector<string> &ans){
        int n=maze.size()-1 ;
        if(i==n && j==n){
            ans.push_back(s) ;
            return ;
        }
        if(i+1<=n && maze[i+1][j]==1 && vis[i+1][j]==0){
            vis[i][j]=1 ;
            f(i+1 , j , maze , s+'D' , vis , ans) ;
            vis[i][j]=0 ;
        }
        if(j-1>=0 && maze[i][j-1]==1 && vis[i][j-1]==0){
            vis[i][j]=1 ;
            f(i , j-1 , maze , s+'L' , vis , ans) ;
            vis[i][j]=0 ;
        }
        if(j+1<=n && maze[i][j+1]==1 && vis[i][j+1]==0){
            vis[i][j]=1 ;
            f(i , j+1 , maze , s+'R' , vis , ans) ;
            vis[i][j]=0 ;
        }
        if(i-1>=0 && maze[i-1][j]==1 && vis[i-1][j]==0){
            vis[i][j]=1 ;
            f(i-1 , j , maze , s+'U' , vis , ans) ;
            vis[i][j]=0 ;
        }
    }
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string> ans ;
        int n=maze.size() ;
        if(maze[0][0]==0 || maze[n-1][n-1]==0) return ans ;
        vector<vector<int>> vis(n , vector<int>(n , 0)) ;
        string s="" ;
        f(0 , 0 , maze , s , vis , ans) ;
       return ans ; 
    }
};

int main(){
Solution s ;
vector<vector<int>> maze={{1 , 0 , 0 , 0} , {1 , 1 , 0 , 1} , {1 , 1 , 0 , 0} , {0 , 1 , 1 , 1}} ;
vector<string> ans=s.ratInMaze(maze) ;
for(auto it : ans) cout<<it<<"  " ;
return 0 ;
}