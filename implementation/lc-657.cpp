// LeetCode 657 — Robot Return to Origin
// https://leetcode.com/problems/robot-return-to-origin/
// Topic: implementation | Tags: strings
// Complexity (yours): O(n) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int u = 0, d = 0, l = 0, r = 0;

        for(int i = 0; i < (int)moves.length(); i++){
            if(moves[i] == 'U') u++;
            else if(moves[i] == 'D') d++;
            else if(moves[i] == 'L') l++;
            else r++;
        }

        if(u - d == 0 && l - r == 0) return true;

        return false; 
    }
};

int main() {
    Solution S;

    cout << boolalpha;
    cout << S.judgeCircle("UD");

    return 0;
}

/*
💭 First Idea: Count U/D/L/R moves and check U == D and L == R.
🧩 Key Property / Invariant: The robot is back iff net vertical and net horizontal displacement are both 0.
✅ Key insight: Move order doesn't matter, only counts.
🔁 Recognition cue for next time: "Returns to origin after a move string" → track (x, y).
⏱  Speed fix for next time: Two ints x, y and return x == 0 && y == 0.
🛠  Review: correct; O(n) — Already optimal.
*/
