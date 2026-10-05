// LeetCode 2006 — Count Number of Pairs With Absolute Difference K
// https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/
// Topic: hashing | Tags: arrays, brute-force
// Complexity (yours): O(n²) time, O(1) space
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

// ===================== ⚡ Optimized =====================
// O(n) instead of O(n^2): count earlier occurrences of x-k and x+k with a frequency table.
class SolutionOptimized {
public:
    int countKDifference(vector<int>& nums, int k) {
        int cnt[101] = {};          // 1 <= nums[i] <= 100
        int res = 0;
        for (int x : nums) {
            if (x - k >= 1)   res += cnt[x - k];
            if (x + k <= 100) res += cnt[x + k];
            cnt[x]++;
        }
        return res;
    }
};

/*
💭 First Idea: Check every pair (i, j) and count those with |a - b| == k.
🧩 Key Property / Invariant: For each x, the matching earlier values are exactly x-k and x+k (k >= 1, so they're distinct).
✅ Key insight: Keep a frequency map of values seen so far and add cnt[x-k] + cnt[x+k] at each step.
🔁 Recognition cue for next time: "count pairs with sum/difference = k" -> one pass with a hash map / count array.
⏱  Speed fix for next time: With values <= 100 a fixed int[101] array beats unordered_map.
🛠  Review: correct (n <= 200 so O(n²) passes); O(n²) -> optimized O(n).
*/
