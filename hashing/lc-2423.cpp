// LeetCode 2423 — Remove Letter To Equalize Frequency
// https://leetcode.com/problems/remove-letter-to-equalize-frequency/
// Topic: hashing | Tags: strings, counting
// Complexity (yours): O(n) time, O(1) space (<= 26 letters)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool equalFrequency(string word) {
        unordered_map<char, int> charcount;
        for(char i : word){
            charcount[i]++;
        }

        unordered_map<int, int> freq;
        for(auto &p : charcount){
            freq[p.second]++;
        }

        if(freq.size() > 2) return false;

        if(freq.size() == 1){
            int f = freq.begin()->first;
            int c = freq.begin()->second;
            return (f == 1 || c == 1);
        }

        auto it = freq.begin();
        
        int f1 = it->first, c1 = it->second;
        it++;
        int f2 = it->first, c2 = it->second;

        if(f1 > f2){
            swap(f1, f2);
            swap(c1, c2);
        }

        if(f1 == 1 && c1 == 1) return true;

        if(f2 - f1 == 1 && c2 == 1) return true;

        return false;
    }
};

int main() {

    Solution S;
    
    cout << boolalpha;
    cout << S.equalFrequency("abcc");

    return 0;
}
/*
💭 First Idea: Count letters, then count how many letters share each frequency and case-split on that map.
🧩 Key Property / Invariant: Valid iff: all freq 1; or one distinct letter; or one letter with freq 1 and rest equal; or one letter with freq f+1 and rest f.
✅ Key insight: Removing exactly one letter only lowers one count by 1, so only these few frequency patterns work.
🔁 Recognition cue for next time: "Remove exactly one element to make counts equal" -> frequency-of-frequencies case analysis (or just try all 26 removals).
⏱  Speed fix for next time: With only 26 letters, brute force (decrement each letter, check all non-zero counts equal) is safer and fast enough.
🛠  Review: correct (stress-tested vs brute force); Already optimal.
*/
