// LeetCode 961 — N-Repeated Element in Size 2N Array
// https://leetcode.com/problems/n-repeated-element-in-size-2n-array/
// Topic: hashing | Tags: math, arrays
// Complexity (yours): O(n) time, O(n) space
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int repeatedNTimes(vector<int> &nums)
    {
        unordered_map<int, int> mp;

        for (int i : nums)
        {
            mp[i]++;
        }

        int max = INT_MIN;
        int ans = 1;

        for (auto &p : mp)
        {
            if (p.second > max)
            {
                max = p.second;
                ans = p.first;
            }
        }
        return ans;
    }
};
int main()
{
    Solution Sol;
    vector<int> nums = {2, 1, 2, 5, 3, 2};

    cout << Sol.repeatedNTimes(nums);

}

// ===================== ⚡ Optimized =====================
// O(1) extra space: n copies among 2n slots => two copies are always at distance 1, 2 or 3.
class SolutionOptimized {
public:
    int repeatedNTimes(vector<int>& nums) {
        for (int i = 1; i < (int)nums.size(); i++) {
            if (nums[i] == nums[i - 1]) return nums[i];
            if (i >= 2 && nums[i] == nums[i - 2]) return nums[i];
            if (i >= 3 && nums[i] == nums[i - 3]) return nums[i];
        }
        return -1;  // unreachable for valid input
    }
};

/*
💭 First Idea: Count frequencies in a hash map and return the most frequent value.
🧩 Key Property / Invariant: One value fills half the array; every other value appears once.
✅ Key insight: So the first value seen twice is the answer — and two of its copies are always within distance <= 3.
🔁 Recognition cue for next time: "One element occupies half the array" → first repeat / neighbour check.
⏱  Speed fix for next time: Return as soon as a count hits 2 — no second pass over the map.
🛠  Review: correct; yours O(n) time O(n) space → optimized O(n) time O(1) space.
*/
