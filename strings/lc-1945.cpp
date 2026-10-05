// LeetCode 1945 — Sum of Digits of String After Convert
// https://leetcode.com/problems/sum-of-digits-of-string-after-convert/
// Topic: strings | Tags: math, implementation
// Complexity (yours): O(|s| + k·d) time, O(|s|) space
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getLucky(string s, int k) {
        string res = "";
        int sum = 0;

        for(char i : s){
            res += to_string(i - 'a' + 1);
        }

        for(int i = 0; i < k; i++){
            for(char i : res){
                int n = int(i - '0');
                sum += n;
            }
            res = to_string(sum);
            sum = 0;
        }
        return stoi(res);
    }
};

int main() {
    Solution S;

    cout << S.getLucky("iiii", 1);
    
}

/*
💭 First Idea: Build the digit string from letter positions, then replace it with its digit sum k times.
🧩 Key Property / Invariant: After the first transform the number is small (<= 9*2*|s|), so later rounds are cheap.
✅ Key insight: You can do the first transform directly: add the digit sum of (c-'a'+1) per letter, skipping the long string.
🔁 Recognition cue for next time: "convert then repeatedly sum digits" -> simulate; at most a few iterations matter.
⏱  Speed fix for next time: Doing the first round inline avoids building a 200-char string.
🛠  Review: correct; O(|s| + k·d) -> Already optimal.
*/
