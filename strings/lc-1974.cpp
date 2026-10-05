// LeetCode 1974 — Minimum Time to Type Word Using Special Typewriter
// https://leetcode.com/problems/minimum-time-to-type-word-using-special-typewriter/
// Topic: strings | Tags: greedy, math
// Complexity (yours): O(n) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTimeToType(string word) {
        int res = word.size(), point = 'a';

        for(char ch : word){
            res += min(abs(ch - point), 26 - abs(point - ch));
            point = ch;
        }
        return res;
    }
};

int main() {
    Solution S;
    
    cout << S.minTimeToType("abc");
}

/*
💭 First Idea: Start the result at n (one second per typed char), then add the circular distance between consecutive letters.
🧩 Key Property / Invariant: On a circle of 26 the shortest move is min(d, 26 - d).
✅ Key insight: Each move is independent, so taking the shortest direction every time is optimal.
🔁 Recognition cue for next time: "pointer on a circular dial" -> min(d, N - d).
⏱  Speed fix for next time: Precount the n type operations up front, as you did.
🛠  Review: correct; O(n) -> Already optimal.
*/
