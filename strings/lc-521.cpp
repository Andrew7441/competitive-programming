// LeetCode 521 — Longest Uncommon Subsequence I
// https://leetcode.com/problems/longest-uncommon-subsequence-i/
// Topic: strings | Tags: math, brain-teaser
// Complexity (yours): O(|a| + |b|) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a == b) return -1;

        return max(a.length(), b.length());
    }
    
};

int main() {
    Solution Sol;

    cout << Sol.findLUSlength("aba","cdc");
    
}

/*
💭 First Idea: If a == b there is no uncommon subsequence (-1), otherwise the longer string itself is the answer.
🧩 Key Property / Invariant: A string can only be a subsequence of another string of equal length if they are identical.
✅ Key insight: If a != b, the longer string (either one when lengths tie) is not a subsequence of the other.
🔁 Recognition cue for next time: "Easy" problem that sounds like heavy DP → look for a one-line trick first.
⏱  Speed fix for next time: Cast lengths to int: max((int)a.size(), (int)b.size()).
🛠  Review: correct; O(|a| + |b|) — Already optimal.
*/
