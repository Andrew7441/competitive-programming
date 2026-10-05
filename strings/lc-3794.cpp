// LeetCode 3794 — Reverse String Prefix
// https://leetcode.com/problems/reverse-string-prefix/
// Topic: strings | Tags: two-pointers
// Complexity (yours): O(k) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reversePrefix(string& s, int k) {
        reverse(s.begin(), s.begin() + k);
        return s; 
    }
};

int main() {
    Solution Sol;

    string s = "abcd";

    cout << Sol.reversePrefix(s, 2);    

    
}
/*
💭 First Idea: std::reverse on the first k characters.
🧩 Key Property / Invariant: Only s[0..k-1] changes; the rest stays.
✅ Key insight: reverse(begin, begin + k) does it in place.
🔁 Recognition cue for next time: "Reverse a prefix/segment" -> std::reverse with iterators.
⏱  Speed fix for next time: One-liner; nothing to speed up.
🛠  Review: correct; Already optimal.
*/
