#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    string getPermutation(int n, int k) {
        string ans="" ;
        int fact=1 ;
        vector<int> num ;
        for(int i=1 ; i<n ; i++){
            fact=fact*i ;
            num.push_back(i) ;
        }
        num.push_back(n) ;
        k-- ;
        while(1){
            ans=ans+to_string(num[k/fact]) ;
            num.erase(num.begin()+k/fact) ;
            if(num.size()==0) break ;
            k=k%fact ;
            fact=fact/num.size() ;
        }
        return ans; 
    }
};

int main(){
Solution s ;
int n=3 , k=3 ;
cout<<s.getPermutation(n , k); 
return 0 ;
}