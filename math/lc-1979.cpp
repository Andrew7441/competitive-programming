// LeetCode 1979 — Find Greatest Common Divisor of Array
// https://leetcode.com/problems/find-greatest-common-divisor-of-array/
// Topic: math | Tags: number-theory, arrays
// Complexity (yours): O(n + max) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int greatest = 1;

        int maxe = *max_element(nums.begin(), nums.end());
        int mine = *min_element(nums.begin(), nums.end());

        for(int i = 1; i <= maxe; i++){
            if(mine % i == 0 && maxe % i == 0){
                greatest = i;
            }
        }

        return greatest;
    }
};

int main() {
    Solution S;

    vector<int> nums{{2,5,6,9,10}};

    cout << S.findGCD(nums);
}

// ===================== ⚡ Optimized =====================
// O(n + log max) instead of O(n + max): Euclid's gcd replaces the divisor loop.
class SolutionOptimized {
public:
    int findGCD(vector<int>& nums) {
        auto [mn, mx] = minmax_element(nums.begin(), nums.end());
        return gcd(*mn, *mx);   // std::gcd from <numeric> (C++17)
    }
};

/*
💭 First Idea: Find min and max, then try every i from 1 to max and keep the last common divisor.
🧩 Key Property / Invariant: gcd(a, b) = gcd(b, a % b) (Euclid), which runs in O(log min(a,b)).
✅ Key insight: Use std::gcd(min, max) instead of scanning candidates.
🔁 Recognition cue for next time: "greatest common divisor" -> std::gcd / __gcd straight away.
⏱  Speed fix for next time: Even with a loop, scan down from min and stop at the first common divisor.
🛠  Review: correct; O(n + max) -> optimized O(n + log max) with std::gcd.
*/
