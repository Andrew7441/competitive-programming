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
💭 First Idea
🧩 Key Property / Invariant
✅ Key insight
🔁 Recognition cue for next time
⏱  Speed fix for next time
*/ 