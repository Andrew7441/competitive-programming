// LeetCode 2389 — Longest Subsequence With Limited Sum
// https://leetcode.com/problems/longest-subsequence-with-limited-sum/
// Topic: binary-search | Tags: greedy, sorting, prefix-sum
// Complexity (yours): O((n + q) log n) time, O(1) extra space
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<int> ans;

        for(int i = 1; i < (int)nums.size(); i++){
            nums[i] = nums[i] + nums[i-1];
        }

        for(int& q : queries){
            ans.push_back(upper_bound(nums.begin(), nums.end(), q) - nums.begin());
        }
        return ans;
    }
};

int main() {
    vector<int> nums{4,5,2,1};
    vector<int> queries{3,10,21};

    Solution S;

    vector<int> res = S.answerQueries(nums, queries);

    for(int i : res){
        cout << i << " ";
    }
}
/*
💭 First Idea: Sort, build prefix sums in place, answer each query with upper_bound.
🧩 Key Property / Invariant: Subsequence order does not matter for the sum, so the best k elements are always the k smallest.
✅ Key insight: After sorting, prefix[k] is the min possible sum of k elements -> largest k with prefix[k] <= q via binary search.
🔁 Recognition cue for next time: "Max count of elements with sum <= limit" -> sort ascending + prefix sums + upper_bound.
⏱  Speed fix for next time: Reuse nums for the prefix array (as you did) - no extra memory, no manual binary search.
🛠  Review: correct; Already optimal.
*/
