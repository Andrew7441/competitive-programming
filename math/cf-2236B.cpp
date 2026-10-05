// Codeforces 2236B — Tatar TV Show
// https://codeforces.com/problemset/problem/2236/B
// Topic: math | Tags: strings, bit-manipulation
// Complexity (yours): O(n) time, O(k) space
#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector<int> parity(k, 0);

    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            parity[i % k] ^= 1;
        }
    }

    for (int x : parity) {
        if (x) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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
💭 First Idea: Positions i and i+k are in the same residue class mod k; each class must contain an even number of 1s.
🧩 Key Property / Invariant: An operation flips two bits of the same class mod k, so the parity of 1s in each class is invariant.
✅ Key insight: Within a class the operations act like adjacent flips on a chain, so even parity is also sufficient.
🔁 Recognition cue for next time: "Flip positions i and i+k" -> split into residue classes mod k and look at parity.
⏱  Speed fix for next time: XOR a parity bit per class in one pass.
🛠  Review: correct; O(n) -> Already optimal.
*/
