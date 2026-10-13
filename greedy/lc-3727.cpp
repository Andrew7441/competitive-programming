#include <bits/stdc++.h>
using namespace std;

/*
https://leetcode.com/problems/maximum-alternating-sum-of-squares/description/?envType=daily-question&envId=2026-10-13
*/

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        long long lSum = 0, gSum = 0, mid = n / 2;

        for(int& i : nums) {
            i = abs(i);
        }

        sort(nums.begin(), nums.end());

        for(int i = 0; i < mid; i++) {
            lSum += nums[i] * nums[i];
        }

        for(int i = mid; i < n; i++) {
            gSum += nums[i] * nums[i];
        }

        return gSum - lSum;
    }
};

int main() {
    std::vector<int> v{1,-1,2,-2,3,-3};
    Solution S;
    std::cout << S.maxAlternatingSum(v) << '\n';
    return 0;
}

/*
💭 first idea
🧩 key property / invariant
✅ key insight
🔁 recognition cue for next time
⏱ speed fix for next time
*/