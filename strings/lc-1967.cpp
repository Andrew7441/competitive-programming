// LeetCode 1967 — Number of Strings That Appear as Substrings in Word
// https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/
// Topic: strings | Tags: implementation
// Complexity (yours): O(p·|w|·|pattern|) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int res = 0;

        for(auto w : patterns){
            if(word.find(w) != std::string::npos){
                res++;
            }
        }
        return res; 
    }
};
int main() {
    vector<string> patterns{"a","abc","bc","d"};
    string word{"abc"};

    Solution S;

    cout << S.numOfStrings(patterns, word);
    
}

/*
💭 First Idea: For each pattern check word.find(pattern) != npos.
🧩 Key Property / Invariant: Constraints are tiny (<= 100 patterns, length <= 100), so naive substring search is fine.
✅ Key insight: std::string::find does the substring check; no need for KMP here.
🔁 Recognition cue for next time: "count patterns contained in a string" with small limits -> find() per pattern.
⏱  Speed fix for next time: Iterate by const reference (const auto& w) to avoid copying each pattern.
🛠  Review: correct; brute force -> Already optimal for these limits.
*/
