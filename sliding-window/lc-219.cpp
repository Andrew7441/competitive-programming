// LeetCode 219 — Contains Duplicate II
// https://leetcode.com/problems/contains-duplicate-ii/
// Topic: sliding-window | Tags: hashing
// Complexity (yours): O(n) time, O(min(n,k)) space
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> set;

        for(int i = 0; i < (int)nums.size(); i++){
            if(i > k){
                set.erase(nums[i - k - 1]);
            }

            if(set.count(nums[i])){
                return true;
            }

            set.insert(nums[i]);
        }
        return false;
    }
};

int main() {
    vector<int> nums{1,2,3,1,2,3};

    Solution S;

    cout << boolalpha;
    cout << S.containsNearbyDuplicate(nums, 2);
}

/*
💭 First Idea: Fixed-size sliding window kept in a hash set; a value already in the set → true.
🧩 Key Property / Invariant: Before checking index i the set contains exactly nums[i-k..i-1].
✅ Key insight: |i - j| <= k only depends on the last k values, so evict nums[i-k-1] as i advances.
🔁 Recognition cue for next time: "Duplicate within distance k" → window hash set (or map value → last index).
⏱  Speed fix for next time: Alternative one-liner: unordered_map last; if (last.count(x) && i - last[x] <= k) return true.
🛠  Review: correct; O(n) time, O(min(n,k)) space — Already optimal.
*/
