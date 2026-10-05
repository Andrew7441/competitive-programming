// Codeforces 2167C — Isamatdin and His Magic Wand!
// https://codeforces.com/problemset/problem/2167/C
// Topic: sorting | Tags: math, constructive
// Complexity (yours): O(n log n) time, O(n) space
#include <bits/stdc++.h>
using namespace std;

/**/

void solve(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int& i : a) cin >> i;

    bool odd = false, even = false;

    for(int& i : a){
        if(i % 2) odd = true;
        else even = true;
    }

    if(even && odd){
        sort(a.begin(), a.end());
    }

    for(int &i: a) cout << i << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}

/*
💭 First Idea: If both parities exist, sort; otherwise print as is.
🧩 Key Property / Invariant: With one odd and one even element, any two elements can be swapped through an opposite-parity 'bridge', so every permutation is reachable.
✅ Key insight: Mixed parity -> fully sortable; single parity -> no swap is possible.
🔁 Recognition cue for next time: "Swap only under a condition" -> check whether a bridge element makes every transposition reachable.
⏱  Speed fix for next time: Try the 3-element case (two same parity + one other) by hand.
🛠  Review: correct; O(n log n) -> Already optimal.
*/
