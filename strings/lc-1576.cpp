// LeetCode 1576 — Replace All ?'s to Avoid Consecutive Repeating Characters
// https://leetcode.com/problems/replace-all-s-to-avoid-consecutive-repeating-characters/
// Topic: strings | Tags: greedy
// Complexity (yours): O(n) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string modifyString(string s) {
        for(size_t i = 0; i < s.length(); i++)
            if(s[i] == '?')
                for(s[i] = 'a'; s[i] <= 'c'; ++s[i])
                    if((i == 0 || s[i-1] != s[i]) && (i == s.length() - 1 || s[i+1] != s[i]))
                        break;

        return s;
    }
 
};

int main() {
    Solution S;

    cout << S.modifyString("?zs");
}

/*
💭 First Idea: Greedily put the first of 'a','b','c' that differs from both neighbours into each '?'.
🧩 Key Property / Invariant: Each position has at most 2 neighbours, so 3 candidate letters always leave one free.
✅ Key insight: Left-to-right greedy works because the left neighbour is already final, and a right '?' gets fixed later.
🔁 Recognition cue for next time: "fill blanks so no two adjacent are equal" -> try 3 letters greedily.
⏱  Speed fix for next time: Loop directly over s[i] = 'a'..'c' as you did; it is compact and safe.
🛠  Review: correct; O(n) -> Already optimal.
*/
