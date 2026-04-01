#include<bits/stdc++.h>
using namespace std ;

 // TC --> O(n^2) && SC --> O(n^2)
 /*
void rotate(vector<vector<int>> & arr){
    int temp[arr.size()][arr[0].size()]={0} ;
    int n=arr.size()-1 ;
    for(int i=0 ; i<arr.size() ; i++){
        for(int j=0 ; j<arr[0].size() ; j++){
            temp[j][n-i]=arr[i][j] ;
        }
    }
    for(int i=0 ; i<arr.size() ; i++){
        for(int j=0 ; j<arr[0].size() ; j++){
            arr[i][j]=temp[i][j] ;
        }
    }
}
*/

//TC --> O(n^2) && SC --> O(1) ;
void rotate(vector<vector<int>> & arr){
    int temp[arr.size()][arr[0].size()]={0} ;
    int n=arr.size()-1 ;
    for(int i=0 ; i<arr.size() ; i++){
        for(int j=0 ; j<arr[0].size() ; j++){
            if(i<j) swap(arr[i][j] , arr[j][i]);
        }
    }
    for(int i=0 ; i<arr.size() ; i++){
        reverse(arr[i].begin() , arr[i].end()) ;
    }
}



int main(){
vector<vector<int>> arr={{1 , 2 , 3 , 4 } , 
                         {5 , 6 , 7 , 8 } , 
                         {9 , 10 , 11 , 12} ,
                         {13 , 14 , 15 , 16 }} ;
cout<<"Before Rotation"<<endl ;
for(int i=0 ; i<arr.size() ; i++){
    for(int j=0 ; j<arr[0].size() ; j++){
        cout<<arr[i][j]<<"  " ;
    }
    cout<<endl ;
}
cout<<endl ;
cout<<"After Rotation"<<endl ;
rotate(arr) ;
for(int i=0 ; i<arr.size() ; i++){
    for(int j=0 ; j<arr[0].size() ; j++){
        cout<<arr[i][j]<<"  " ;
    }
    cout<<endl ;
}
return 0 ;
}