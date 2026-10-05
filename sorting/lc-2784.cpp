// LeetCode 2784 — Check if Array is Good
// https://leetcode.com/problems/check-if-array-is-good/
// Topic: sorting | Tags: hashing, arrays
// Complexity (yours): O(n log n) time, O(n) space
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        vector<int> base(n);

        std::iota(base.begin(), base.end(), 1);
        base[n - 1] = n - 1;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++){
            if(base[i] != nums[i]) return false;
        }

        return true;
    }
};
int main() {
    Solution S;
    vector<int> nums{3, 4, 4, 1, 2, 1};

    cout << boolalpha;
    cout << S.isGood(nums);
    
    return 0;
}

// ===================== ⚡ Optimized =====================
// O(n) instead of O(n log n): counting beats sorting since values must lie in [1, n].
class SolutionOptimized {
public:
    bool isGood(vector<int>& nums) {
        int n = (int)nums.size() - 1;           // candidate base[n]
        vector<int> cnt(n + 2, 0);
        for (int x : nums) {
            if (x < 1 || x > n) return false;
            cnt[x]++;
        }
        for (int v = 1; v < n; v++)
            if (cnt[v] != 1) return false;
        return n >= 1 && cnt[n] == 2;
    }
};

/*
💭 first idea: sort nums and compare with the explicit base array [1, 2, ..., n-1, n-1] (n = nums.size()).
🧩 key property / invariant: base[m] has length m+1, so m is forced = size-1; then 1..m-1 appear once and m twice.
✅ key insight: the max element is determined by the length - just verify counts.
🔁 recognition cue for next time: "is it a permutation (with a twist)?" -> counting array of size n.
⏱ speed fix for next time: count occurrences in O(n) instead of sorting.
🛠 Review: correct; yours O(n log n) -> optimized O(n) counting (both fine for n <= 100).
*/