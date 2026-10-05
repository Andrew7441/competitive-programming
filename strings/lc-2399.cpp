// LeetCode 2399 — Check Distances Between Same Letters
// https://leetcode.com/problems/check-distances-between-same-letters/
// Topic: strings | Tags: hashing
// Complexity (yours): O(n) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<int> firstpos(26, -1);

        for(int i = 0; i < (int)s.size(); i++){
            int idx = s[i] - 'a';
            if(firstpos[idx] == -1){
                firstpos[idx] = i;
            }else{
                if(i - firstpos[idx] - 1 != distance[idx]){
                    return false; 
                }
            }
        }
        return true; 
    }
};

int main() {
    cout << boolalpha;
    Solution Sol;
    vector<int> distance{1,3,0,5,0,0,0,0,0,0,0,0,
                        0,0,0,0,0,0,0,0,0,0,0,0,0,0};


    cout << Sol.checkDistances("abaccb", distance);

    
}
/*
💭 First Idea: Remember the first index of each letter; at the second occurrence compare the gap with distance[].
🧩 Key Property / Invariant: Each letter appears exactly twice, so the gap is (second - first - 1).
✅ Key insight: A 26-slot array of first positions is all the state needed.
🔁 Recognition cue for next time: "Each letter appears exactly twice" -> store first position in int[26].
⏱  Speed fix for next time: Write it straight with an int[26] filled with -1; no maps.
🛠  Review: correct; Already optimal.
*/
