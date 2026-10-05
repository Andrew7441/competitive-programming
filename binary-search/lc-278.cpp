// LeetCode 278 — First Bad Version
// https://leetcode.com/problems/first-bad-version/
// Topic: binary-search
// Complexity (yours): O(log n) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

int bad;  

bool isBadVersion(int version) {
    return version >= bad;
}

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, h = n;
        while (l < h) {
            int mid = l + (h - l) / 2; 
            if (isBadVersion(mid))
                h = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};

int main() {
    int n = 5;
    bad = 4; 

    Solution sol;
    cout << "First bad version: " << sol.firstBadVersion(n) << endl;

    return 0;
}

/*
💭 First Idea: Lower-bound binary search on [1, n] for the first true of a monotone predicate.
🧩 Key Property / Invariant: Answer always stays inside [l, h]; isBadVersion is false…false true…true.
✅ Key insight: mid = l + (h - l) / 2 avoids int overflow when n is close to 2^31 - 1.
🔁 Recognition cue for next time: "First index/version where a condition becomes true" → binary search.
⏱  Speed fix for next time: Reuse the l < h, h = mid / l = mid + 1 template — no off-by-one thinking.
🛠  Review: correct; O(log n) API calls — Already optimal.
*/
