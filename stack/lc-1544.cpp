// LeetCode 1544 — Make The String Great
// https://leetcode.com/problems/make-the-string-great/
// Topic: stack | Tags: strings
// Complexity (yours): O(n) time, O(n) space
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string makeGood(string s) {
       string ans;

       for(char c : s){
        if(!ans.empty() && abs(ans.back() - c) == 32){
            ans.pop_back();
        }else{
            ans.push_back(c);
        }
       }

       return ans;
    }
};

int main() {
    Solution S;

    cout << S.makeGood("leEeetcode");

    return 0;
}

/*
💭 First Idea: Use the answer string as a stack; pop when the top and the current char are the same letter in different case.
🧩 Key Property / Invariant: Removing an adjacent bad pair can create a new one, and the stack handles that chain automatically.
✅ Key insight: 'a' and 'A' differ by exactly 32 in ASCII, so abs(x - y) == 32 detects a bad pair.
🔁 Recognition cue for next time: "repeatedly remove adjacent pairs" -> stack (like valid parentheses).
⏱  Speed fix for next time: Use std::string as the stack directly (as you did).
🛠  Review: correct; O(n) -> Already optimal.
*/
