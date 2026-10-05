// Codeforces 2236C — Omsk Programmers
// https://codeforces.com/problemset/problem/2236/C
// Topic: brute-force | Tags: math, greedy
// Complexity (yours): O(log_x(a) * log_x(b)) time, O(log) space
#include <bits/stdc++.h>
using namespace std;

/**/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll a, b, x;
    cin >> a >> b >> x;

    vector<pair<ll, int>> va, vb;

    for (int operations = 0;; operations++) {
        va.push_back({a, operations});
        if (a == 0) break;
        a /= x;
    }

    for (int operations = 0;; operations++) {
        vb.push_back({b, operations});
        if (b == 0) break;
        b /= x;
    }

    ll answer = LLONG_MAX;

    for (auto [valueA, operationsA] : va) {
        for (auto [valueB, operationsB] : vb) {
            ll cost = operationsA + operationsB
                    + abs(valueA - valueB);

            answer = min(answer, cost);
        }
    }

    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}

/*
💭 First Idea: Try every number of divisions for a and for b (~30 each), then close the gap with +1s.
🧩 Key Property / Invariant: Adding before dividing is never better than adding after: (v + k) / x gains at most ceil(k / x) <= k.
✅ Key insight: Optimal plan = divide a i times, b j times, then pay |a_i - b_j|; enumerate all (i, j).
🔁 Recognition cue for next time: "+1 or divide by x, make equal" -> only O(log) distinct values per number, enumerate them.
⏱  Speed fix for next time: List the division chain of each number and try every pair.
🛠  Review: correct; O(log^2) -> Already optimal (stress-tested vs BFS; x >= 2 so the chains terminate).
*/ 