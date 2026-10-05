// LeetCode 1984 — Minimum Difference Between Highest and Lowest of K Scores
// https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/
// Topic: sorting | Tags: sliding-window
// Complexity (yours): O(n log n) time, O(1) extra space
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

/*
💭 First Idea: Sort, then slide a window of size k and minimise nums[i+k-1] - nums[i].
🧩 Key Property / Invariant: In sorted order the best k elements are always contiguous.
✅ Key insight: After sorting only the window endpoints matter.
🔁 Recognition cue for next time: "choose k elements to minimise max - min" -> sort + fixed-size window.
⏱  Speed fix for next time: The k == 1 special case is already covered by the loop (difference 0).
🛠  Review: correct; O(n log n) -> Already optimal.
*/
