// Codeforces 2167B — Your Name
// https://codeforces.com/problemset/problem/2167/B
// Topic: hashing | Tags: strings
// Complexity (yours): O(n) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

/**/

void solve(){
    int n;
    cin >> n;

    string s, t;
    cin >> s >> t;

    vector<int> m1(26), m2(26);

    for(char& c : s){
        m1[c - 'a']++;
    }
    for(char& c : t){
        m2[c - 'a']++;
    }

    for(int i = 0; i < 26; i++){
        if(m1[i] != m2[i]){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while(q--){
        solve();
    }

    return 0;
}

/*
💭 First Idea: Compare the 26-letter frequency arrays of s and t.
🧩 Key Property / Invariant: Rearranging keeps the multiset of letters.
✅ Key insight: Two strings are anagrams iff their letter counts match.
🔁 Recognition cue for next time: "Can s be rearranged into t" -> frequency count (or sort both).
⏱  Speed fix for next time: One array: ++ for s, -- for t, then check all zero.
🛠  Review: correct; O(n) -> Already optimal.
*/
