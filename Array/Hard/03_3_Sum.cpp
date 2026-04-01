#include<bits/stdc++.h>
using namespace std ;
 
// TC --> O(n^3)
/*
vector<vector<int>> three_sum(vector<int> & arr){
    set<vector<int>> st ;
    for(int i=0 ; i<arr.size() ; i++){
        for(int j=i+1 ; j<arr.size() ; j++){
            for(int k=j+1 ; k<arr.size() ; k++){
                if((arr[i]+arr[j]+arr[k])==0){
                    vector<int> temp={arr[i] , arr[j] , arr[k]} ;
                    sort(temp.begin() , temp.end()) ;
                    st.insert(temp) ;
                }
            }
        }
        vector<vector<int>> ans(st.begin() , st.end()) ;
        return ans ;
    }
}
*/

//TC --> O(n^2 logn)
/*
vector<vector<int>> three_sum(vector<int> & arr){
    set<vector<int>> st ;
    set<int> hashset ;
    for(int i=0 ; i<arr.size() ; i++){
        for(int j=i+1 ; j<arr.size() ; j++){
            hashset.insert(arr[j]) ;
            int k=-(arr[i]+arr[j]) ;
            if(hashset.find(k)!=hashset.end()){
                 vector<int> temp={arr[i] , arr[j] , k} ;
                 sort(temp.begin() , temp.end()) ;
                 st.insert(temp) ;
            }   
        }
        hashset.clear() ;
        vector<vector<int>> ans(st.begin() , st.end()) ;
        return ans ;
    }
}
*/
//TC --> O(n^2)
vector<vector<int>> three_sum(vector<int> & arr){
    vector<vector<int>> ans ;
    sort(arr.begin() , arr.end()) ;
    for(int i=0 ; i<arr.size() ; i++){
        if(i>0 && arr[i]==arr[i-1]) continue;
        int j=i+1 , k=arr.size()-1 ;
        while(j<k){
            int sum=arr[i]+arr[j]+arr[k] ;
            if(sum>0){
                k-- ;
            }
            else if(sum<0){
                j++ ;
            }
            else{
                vector<int> temp={arr[i], arr[j] , arr[k]} ;
                ans.push_back(temp) ;
                j++ ;
                k-- ;
                while(j<k && arr[j]==arr[j-1]) j++ ;
                while(j<k && arr[k]==arr[k+1]) k-- ;
            }
        }
    }
    return ans ;
}


int main(){
vector<int> arr={-1 , 0 , 1 , 2 , -1 , -4} ;
vector<vector<int>> ans=three_sum(arr) ;
for(int i=0 ; i<ans.size() ; i++){
    cout<<"[" ;
    for(int j=0 ; j<ans[i].size() ; j++){
        cout<<ans[i][j]<<" " ;
    }
    cout<<"]  ";
}
return 0 ;
}