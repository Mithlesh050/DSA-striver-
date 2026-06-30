#include<bits/stdc++.h>
using namespace std ;


// TC --> O(n logn)
class Solution {
private:
    void lower_bound(int key, vector<int>& arr) {
        int ans = arr.size();
        int low = 0, high = arr.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] < key)
                low = mid + 1;
            else {
                ans = mid;
                high = mid - 1;
            }
        }
        arr[ans] = key;
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        ans.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (ans[ans.size() - 1] < nums[i])
                ans.push_back(nums[i]);
            else
                lower_bound(nums[i], ans);
        }
        return ans.size();
    }
};

int main(){
Solution s ;
vector<int> nums={10,9,2,5,3,7,101,18} ;
cout << s.lengthOfLIS(nums);
return 0 ;
}