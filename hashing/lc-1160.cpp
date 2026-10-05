// LeetCode 1160 — Find Words That Can Be Formed by Characters
// https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/
// Topic: hashing | Tags: strings, counting
// Complexity (yours): O(|chars| + Σ|word|) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int charfreq[26] = {0};
        int res = 0;

        for(char c : chars){
            charfreq[c - 'a']++;
        }

        for(const string& word : words){
            int freq[26] = {0};

            memcpy(freq, charfreq, sizeof(freq));

            bool canform = true;
            for(char c : word){
                if(--freq[c - 'a'] < 0){
                    canform = false;
                    break;
                }
            }

            if(canform) res += word.length();
        }
        return res; 
    }
};
int main() {

    vector<string> words{"cat","bt","hat","tree"};
    string chars{"atach"};

    Solution S;

    cout << S.countCharacters(words, chars);
    
}

/*
💭 First Idea: 26-letter frequency array of chars; for each word copy it and decrement, fail if any count goes negative.
🧩 Key Property / Invariant: A word is formable iff for every letter count_in_word <= count_in_chars.
✅ Key insight: Fixed-size 26 counts make the per-word copy O(1).
🔁 Recognition cue for next time: "Can X be built from the letters of Y" → frequency comparison (like Ransom Note).
⏱  Speed fix for next time: Nothing to fix; early break on the first negative count is already there.
🛠  Review: correct; O(|chars| + Σ|word|) — Already optimal.
*/
