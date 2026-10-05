// LeetCode 2395 — Find Subarrays With Equal Sum
// https://leetcode.com/problems/find-subarrays-with-equal-sum/
// Topic: hashing | Tags: arrays
// Complexity (yours): O(n) time, O(n) space
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        if(nums.size() < 2) return false;

        unordered_map<int, int> freq;

        for(int i = 0; i < (int)nums.size() - 1; i++){
            int sum = nums[i] + nums[i+1];
            if(freq[sum] > 0) return true;
            freq[sum]++;
        }
        return false;
    }
};

int main() {
    vector<int> nums{4,2,4};

    Solution S;

    cout << S.findSubarrays(nums);
    
}

/*
2395. Find Subarrays With Equal Sum
https://leetcode.com/problems/find-subarrays-with-equal-sum/description/

Given a 0-indexed integer array nums, determine whether there exist two subarrays of length 2 with equal sum. Note that the two subarrays must begin at different indices.

Return true if these subarrays exist, and false otherwise.

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:

Input: nums = [4,2,4]
Output: true
Explanation: The subarrays with elements [4,2] and [2,4] have the same sum of 6.

Example 2:

Input: nums = [1,2,3,4,5]
Output: false
Explanation: No two subarrays of size 2 have the same sum.

Example 3:

Input: nums = [0,0,0]
Output: true
Explanation: The subarrays [nums[0],nums[1]] and [nums[1],nums[2]] have the same sum of 0. 
Note that even though the subarrays have the same content, the two subarrays are considered different because they are in different positions in the original array.
*/
/*
💭 First Idea: Hash every adjacent-pair sum; a repeated sum means two equal subarrays.
🧩 Key Property / Invariant: Two length-2 subarrays at different starts with the same sum <=> some pair sum appears twice.
✅ Key insight: Only n-1 candidate sums exist, so a seen-set detects a duplicate in one pass.
🔁 Recognition cue for next time: "Do two windows/pairs share a value?" -> store each value in a hash set, check before insert.
⏱  Speed fix for next time: unordered_set<int> + insert().second is shorter than a freq map (sum of two values fits int: |sum| <= 2e9).
🛠  Review: correct; Already optimal.
*/
