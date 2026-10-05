// Codeforces 2065B — Skibidus and Ohio
// https://codeforces.com/problemset/problem/2065/B
// Topic: greedy | Tags: strings
// Complexity (yours): O(|s|) per test
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector <ll>;
using ii = pair <ll, ll>;
using vii = vector <ii>;

void tc () {
    string str;
    cin >> str;
    for (ll i = 1; i < str.size(); i++) {
        if (str[i-1] == str[i]) {
            cout << "1\n";
            return;
        }
    }
    cout << str.size() << '\n';
}

int main () {
    cin.tie(nullptr) -> sync_with_stdio(false);
    ll T; cin >> T; while (T--) { tc(); }
    return 0;
}

/*
💭 First Idea: If any adjacent pair is equal, answer 1; else the length is unchanged.
🧩 Key Property / Invariant: With one equal pair you can keep recreating an equal pair and shrink to 1.
✅ Key insight: Operation can cascade: replace s_i with neighbour's letter to form a new equal pair.
🔁 Recognition cue for next time: "Repeated delete-if-equal-neighbour" -> check if one move exists, then it chains.
⏱  Speed fix for next time: Use size_t / int consistently in the loop.
🛠  Review: correct; Already optimal.
*/
