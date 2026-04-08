#include<bits/stdc++.h>
using namespace std ;
 

// TC --> O(n^2) && SC --> O(3)
/*
int totalFruit(vector<int>& fruits) {
        int ans=0 ;
        for(int i=0 ; i<fruits.size() ; i++){
            set<int> st ;
            for(int j=i ; j<fruits.size() ; j++){
                 st.insert(fruits[j]) ;
                 if(st.size()>2){
                    break ;
                 }
                 ans=max(ans , j-i+1) ;
            }
        }
        return ans ;
    }
*/

// TC --> O(2n) & SC --> O(3) 
/*
int totalFruit(vector<int>& fruits) {
        int ans=0 , left=0 , right=0 ;
        unordered_map<int , int> mp ;
        while(right<fruits.size()){
            mp[fruits[right]]++ ;
            while(mp.size()>2){
                mp[fruits[left]]-- ;
                if(mp[fruits[left]]==0) 
                mp.erase(fruits[left]) ;
                left++ ;
            }
            ans=max(ans , right-left+1) ;
            right++ ;
        } 
        return ans ;
    }
*/

// TC --> O(n) & SC --> O(3)
int totalFruit(vector<int>& fruits) {
        int ans=0 , left=0 , right=0 ;
        unordered_map<int , int> mp ;
        while(right<fruits.size()){
            mp[fruits[right]]++ ;
            if(mp.size()>2){
                mp[fruits[left]]-- ;
                if(mp[fruits[left]]==0) mp.erase(fruits[left]) ;
                left++ ;
                right++ ;
            }
            else{
                ans=max(ans , right-left+1);
                right++ ;
            }
        } 
        return ans ;
    }


int main(){
vector<int> arr={3 , 3 , 3 , 1 , 2 , 1 , 1 , 2 , 3 , 3 , 4} ;
cout<<totalFruit(arr) ;
return 0 ;
}