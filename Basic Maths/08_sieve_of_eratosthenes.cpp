#include<bits/stdc++.h>
using namespace std ;
 

// TC --> O(nlog(logn))
vector<int> sieve(int n) {
        int arr[n+1] ;
        for(int i=0 ; i<=n ; i++){
            arr[i]=1 ;
        }
        for(int i=2 ; i*i<=n ; i++){
            if(arr[i]==1)
            for(int j=i*i ; j<=n ; j=j+i){
                arr[j]=0 ;
            }
        }
        vector<int> ans ;
        for(int i=2 ; i<=n ; i++){
            if(arr[i]==1)
            ans.push_back(i) ;
        }
        return ans ;
    }

int main(){
int n=10 ;
vector<int> ans=sieve(n) ;
for(int i=0 ; i<ans.size() ; i++){
    cout<<ans[i]<<" " ;
}
return 0 ;
}