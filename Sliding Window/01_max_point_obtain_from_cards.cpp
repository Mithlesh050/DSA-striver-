#include<bits/stdc++.h>
using namespace std ;

// TC --> O(2K)
int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size() ;
        int start=k-1 , end=n-1 ;
        int lsum=0 , rsum=0 , maxsum=0 ;
        for(int i=0 ; i<=start ; i++)
        lsum=lsum+cardPoints[i] ;
        maxsum=lsum ;
        start-- ;
        while(start>=-1){
            lsum=lsum-cardPoints[start+1] ;
            rsum=rsum+cardPoints[end] ;
            maxsum=max(maxsum , lsum+rsum) ;
            start-- ;
            end-- ;
        }
        return maxsum ;
    }

int main(){
vector<int> arr={1 , 2 , 3 , 4 , 5 , 6 , 1} ;
int k=3 ;
cout<<maxScore(arr , k) ;
return 0 ;
}