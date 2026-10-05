// Codeforces 1915D — Unnatural Language Processing
// https://codeforces.com/problemset/problem/1915/D
// Topic: strings | Tags: greedy
// Complexity (yours): O(n) time, O(n) space
#include <bits/stdc++.h>
using namespace std;

/**/

void solve(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    string res = "";

    while(!s.empty()){
        int x;

        if(s.back() == 'a' || s.back() == 'e') x = 2;
        else x = 3;

        while(x--){
            res += s.back();
            s.pop_back();
        }
        res += '.';
    }
    res.pop_back();
    reverse(res.begin(), res.end());

    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}

/*
💭 First Idea: Parse from the back: if the last char is a vowel the syllable is CV (2 chars), else CVC (3 chars).
🧩 Key Property / Invariant: Every syllable ends with a vowel (CV) or a consonant (CVC), and the split is unique.
✅ Key insight: Reading from the end removes the ambiguity of whether the next consonant belongs to this syllable.
🔁 Recognition cue for next time: 'Unique split into CV / CVC' -> parse from the end (or put a dot before each consonant followed by a vowel).
⏱  Speed fix for next time: Alternative forward rule: put '.' before s[i] when s[i] is a consonant and s[i+1] a vowel (i > 0).
🛠  Review: correct; Already optimal.
*/