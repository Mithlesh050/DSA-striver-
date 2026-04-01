#include<bits/stdc++.h>
using namespace std ;
 
//  Brutforce 
/*
void markrow(vector<vector<int>> &arr , int  row)
{
    for(int j=0 ; j<arr[row].size() ; j++){
        if(arr[row][j]!=0){
            arr[row][j]=-1 ;
        }
    }
}

void markcol(vector<vector<int>> &arr , int  col)
{
    for(int j=0 ; j<arr.size() ; j++){
        if(arr[j][col]!=0){
            arr[j][col]=-1 ;
        }
    }
}

void last_step(vector<vector<int>> & arr){
    for(int i=0 ; i<arr.size() ; i++){
    for(int j=0 ; j<arr[i].size() ; j++)
    if(arr[i][j]==-1) arr[i][j]=0 ;
   }
}

// TC --> O(n^3);
void set_zero(vector<vector<int>> & arr){
     for(int i=0 ; i<arr.size() ; i++){
        for(int j=0 ; j<arr[i].size() ; j++){
            if(arr[i][j]==0){
                markrow(arr , i) ;
                markcol(arr , j) ;
            }
        }
     }
     last_step(arr) ;
}
*/

//Better 
//TC--> O(n^2) ;
/*
void set_zero(vector<vector<int>> & arr){
    int row[arr.size()]={0} ;
    int col[arr[0].size()]={0} ;
    for(int i=0 ; i<arr.size() ; i++){
       for(int j=0 ; j<arr[i].size() ; j++)
          if(arr[i][j]==0){
            row[i]=1 ;
            col[j]=1 ;
         }
    }
    for(int i=0 ; i<arr.size() ; i++){
     for(int j=0 ; j<arr[i].size() ; j++)
          if(arr[i][j]==1){
            if(row[i]==1 || col[j]==1)
            arr[i][j]=0 ;
          }
   }
}
*/


// without extra space TC-->O(n^2) ;
void set_zero(vector<vector<int>> & arr){
    int col0=1 ;
    for(int i=0 ; i<arr.size() ; i++){
        for(int j=0 ; j<arr[0].size() ; j++){
            if(arr[i][j]==0){
                arr[i][0]=0 ;
                if(j!=0)
                arr[0][j]=0 ;
                else
                col0=0 ;
            }
        }
    }
    for(int i=1 ; i<arr.size() ; i++){
        for(int j=1 ; j<arr[0].size() ; j++){
            if(arr[i][j]!=0){
                if(arr[i][0]==0 || arr[0][j]==0){
                    arr[i][j]=0 ;
                }
            }
        }
    }
    if(arr[0][0]==0){
        for(int i=0 ; i<arr[0].size() ; i++)
        arr[0][i]=0 ;
    }
    if(col0==0){
        for(int i=0 ; i<arr.size() ; i++)
        arr[i][0]=0 ;
    }
}


int main(){
vector<vector<int>> arr={{1 , 1 , 1 , 1} , {1 , 0 , 0 , 1} , {1 , 1 , 0 , 1} , {1 , 1 , 1 , 1}} ;
cout<<"Before set zero "<<endl ;
for(int i=0 ; i<arr.size() ; i++){
    for(int j=0 ; j<arr[i].size() ; j++)
    cout<<arr[i][j]<<"  " ;
    cout<<endl ;
}
cout<<endl ;
cout<<"After set zero "<<endl;
set_zero(arr);
for(int i=0 ; i<arr.size() ; i++){
    for(int j=0 ; j<arr[i].size() ; j++)
    cout<<arr[i][j]<<"  " ;
    cout<<endl ;
}

return 0 ;
}