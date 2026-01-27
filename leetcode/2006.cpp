#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int res = 0;

        for(int i = 0; i < (int)nums.size(); i++){
            for(int j = i+1; j < (int)nums.size(); j++){
                if(abs(nums[j] - nums[i]) == k){
                    res++;
                }
            }
        }

        return res;
    }
};

int main() {
    vector<int> nums{1,2,2,1};

    Solution S;

    cout << S.countKDifference(nums, 1);
}