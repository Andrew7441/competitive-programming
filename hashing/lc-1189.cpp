// LeetCode 1189 — Maximum Number of Balloons
// https://leetcode.com/problems/maximum-number-of-balloons/
// Topic: hashing | Tags: strings, counting
// Complexity (yours): O(n) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> mp;

        for(char c : text) mp[c]++;

        return min(mp['b'], min(mp['a'], min(mp['l']/2, min(mp['o']/2, mp['n']))));
    }
};
int main() {
    Solution Sol;
    cout << Sol.maxNumberOfBalloons("loonbalxballpoon");
}

/*
💭 First Idea: Count letters and take the min over b, a, l/2, o/2, n.
🧩 Key Property / Invariant: Each "balloon" uses b, a, n once and l, o twice.
✅ Key insight: Answer is limited by the scarcest letter after dividing by how many it needs.
🔁 Recognition cue for next time: "How many copies of word W from these letters" → min over cnt[c] / need[c].
⏱  Speed fix for next time: int cnt[26] instead of unordered_map; min({...}) with an initializer list.
🛠  Review: correct; O(n) — Already optimal.
*/
