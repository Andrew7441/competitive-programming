#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int ans = INT_MAX;
        
        if(k == 1) return 0;

        sort(nums.begin(), nums.end());

        for(int i = 0; i + k - 1 < (int)nums.size(); i++){
            ans = min(ans, nums[i + k - 1] - nums[i]);
        }

        return ans;
    }
};


int main() {
    vector<int> nums{9,4,1,7};

    Solution S;

    cout << S.minimumDifference(nums, 2);
}