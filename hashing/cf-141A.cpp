// Codeforces 141A — Amusing Joke
// https://codeforces.com/problemset/problem/141/A
// Topic: hashing | Tags: strings
// Complexity (yours): O(n) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t, x;
    cin >> s >> t >> x;

    char freq[26]{0};
    char freq1[26]{0};

    bool ok = true; 
    for(size_t i = 0; i < s.length(); i++){
        freq[s[i] - 'A']++;
    }

    for(size_t i = 0; i < t.length(); i++){
        freq[t[i] - 'A']++;
    }

    for(size_t i = 0; i < x.length(); i++){
        freq1[x[i] - 'A']++;
    }

    for(size_t i = 0; i < 26; i++){
        if(freq[i] != freq1[i]){
            ok = false; 
            break;
        }
    }

    if(ok){
        cout << "YES";
    }else{
        cout << "NO";
    }

    return 0;
}

/*
💭 First Idea: Count letters of guest+host and of the pile; compare the 26 counts.
🧩 Key Property / Invariant: Pile is valid iff it is an anagram of guest+host.
✅ Key insight: Frequency arrays (or sort both strings) decide anagrams.
🔁 Recognition cue for next time: 'Can letters be rearranged into...' -> frequency counting.
⏱  Speed fix for next time: Use int freq[26], not char: s+t can reach 200 and overflows a char (works here only by luck).
🛠  Review: correct; Already optimal (but use int counters).
*/
