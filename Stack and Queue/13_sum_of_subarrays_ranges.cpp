#include<bits/stdc++.h>
using namespace std ;
 
// TC --> O(n^2)
long long subArrayRanges(vector<int>& nums) {
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            int smallest = INT_MAX, largest = INT_MIN;
            for (int j = i; j < nums.size(); j++) {
                if (smallest > nums[j])
                    smallest = nums[j];
                if (largest < nums[j])
                    largest = nums[j];
                sum += (largest - smallest);
            }
        }
        return sum;
    }

// optimal TC--> O(10n)
/*
long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxi(nums)-sumSubarrayMins(nums) ; // from previous problem
    }
*/

int main(){
vector<int> arr={1,2,3} ;
cout<<subArrayRanges(arr) ;
return 0 ;
}