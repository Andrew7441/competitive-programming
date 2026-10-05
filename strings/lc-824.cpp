// LeetCode 824 — Goat Latin
// https://leetcode.com/problems/goat-latin/
// Topic: strings | Tags: implementation
// Complexity (yours): O(n + W²) time (output size), O(n + W²) space
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string toGoatLatin(string sentence) {
      string res = "";
      istringstream ss(sentence);
      int num = 1;
      string word; 
      while(ss >> word){
        char ch = tolower(word[0]);
        if(ch == 'a' || ch == 'e' || ch == 'o' || ch == 'i' || ch == 'o' || ch == 'u' ){
            res += word + "ma";
        }else{
            char first = word[0];
            word.erase(0, 1);
            word.push_back(first);
            res += word + "ma";
        }
        res += string(num, 'a');
        num++;
        res += " ";
      }
      res.pop_back();
      return res;
    }
};

int main() {
    string sentence = "I speak Goat Latin";

    Solution S;

    cout << S.toGoatLatin(sentence) << endl;
}

/*
💭 First Idea: Tokenize with istringstream; vowel → word + "ma", else rotate first letter to the end + "ma"; then i copies of 'a'.
🧩 Key Property / Invariant: Word i (1-based) gets exactly i trailing 'a's.
✅ Key insight: tolower() on the first char handles uppercase vowels.
🔁 Recognition cue for next time: Rule-based word transform → istringstream tokenizing + direct implementation.
⏱  Speed fix for next time: string("aeiouAEIOU").find(c) != npos instead of a chain of || ('o' is checked twice).
🛠  Review: correct; O(output size) — Already optimal.
*/
