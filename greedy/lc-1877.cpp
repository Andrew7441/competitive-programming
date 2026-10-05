// LeetCode 1877 — Minimize Maximum Pair Sum in Array
// https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/
// Topic: greedy | Tags: sorting, two-pointers
// Complexity (yours): O(n log n) time, O(n) space
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<pair<int, int>> v;
        int i = 0, j = nums.size() - 1;

        while(i < j){
            v.push_back({nums[i], nums[j]});
            i++;
            j--;
        }
        int max = INT_MIN;
        for(auto& p : v){
            int sum = p.first + p.second;
            if(sum > max){
                max = sum;
            }
        }
        return max;

    }
};

int main() {
    vector<int> nums{3,5,4,2,4,6};

    Solution S;

    cout << S.minPairSum(nums);
}

/*
💭 First Idea: Sort, pair smallest with largest moving inward, and return the largest pair sum.
🧩 Key Property / Invariant: Exchange argument: pairing the max with anything other than the min can only increase the worst pair.
✅ Key insight: After sorting the answer is max(nums[i] + nums[n-1-i]).
🔁 Recognition cue for next time: "pair up elements to minimise the max (or maximise the min) pair sum" -> sort + two pointers from both ends.
⏱  Speed fix for next time: Skip the pairs vector and take the max inside the two-pointer loop (O(1) extra).
🛠  Review: correct (stress-tested vs brute force); O(n log n) -> Already optimal (the extra vector is just unnecessary).
*/
