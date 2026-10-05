// LeetCode 3379 — Transformed Array
// https://leetcode.com/problems/transformed-array/
// Topic: arrays | Tags: simulation, math
// Complexity (yours): O(n) time, O(n) space
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
       int n = nums.size();
       vector<int> res(n);

       for(int i = 0; i < nums.size(); i++){
        int idx = (i + nums[i]) % n; 
        if(idx < 0) idx += n;
        res[i] = nums[idx];
       } 
       return res;
    }
};
int main() {
    vector<int> nums{3,-2,1,1};
    Solution s;

    vector<int> result = s.constructTransformedArray(nums);

    for(auto& i: result)
        cout << i << " ";
    
    return 0;
}
/*
💭 First Idea: For each i, jump nums[i] steps cyclically and copy the value found there.
🧩 Key Property / Invariant: Index (i + nums[i]) mod n must be normalized to [0, n) because C++ % can be negative.
✅ Key insight: ((i + x) % n + n) % n is the safe circular index.
🔁 Recognition cue for next time: "Move left/right on a circular array" -> modular index with the +n fix.
⏱  Speed fix for next time: Write the ((x % n) + n) % n idiom directly.
🛠  Review: correct; Already optimal.
*/
