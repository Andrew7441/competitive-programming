// LeetCode 1556 — Thousand Separator
// https://leetcode.com/problems/thousand-separator/
// Topic: strings | Tags: implementation
// Complexity (yours): O(d) time, O(d) space
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string thousandSeparator(int n) {
        string s = to_string(n);
        int count = 0;
        string res = "";

        for(int i = s.size() - 1; i >= 0; i--){
            if(count == 3){
                res.push_back('.');
                count = 0;
            }
            res.push_back(s[i]);
            count++;
        }

        reverse(res.begin(), res.end());

        return res;
    }
};

int main() {

    Solution S;

    cout << S.thousandSeparator(1234);
    
}

/*
💭 First Idea: Walk the digits from the right, insert '.' every 3 digits, then reverse.
🧩 Key Property / Invariant: Groups are counted from the least significant digit.
✅ Key insight: Building in reverse and flipping once avoids awkward index math.
🔁 Recognition cue for next time: "format a number in groups" -> iterate from the end with a counter.
⏱  Speed fix for next time: Inserting only when count == 3 before pushing avoids a leading '.'.
🛠  Review: correct; O(d) -> Already optimal.
*/
