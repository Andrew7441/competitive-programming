// Codeforces 2169A — Alice and Bob
// https://codeforces.com/problemset/problem/2169/A
// Topic: greedy | Tags: binary-search
// Complexity (yours): O(n) time, O(n) space
// ⚠️ Review: on a tie left == right > 0 printing 0 is not optimal (a=5, v=[4,6] -> 0 points instead of 1); see corrected version below.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//https://codeforces.com/contest/2169/problem/A Alice and Bob

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        ll a;
        cin >> n >> a;
        vector<ll> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];

        int left = lower_bound(v.begin(), v.end(), a) - v.begin();
        int right = n - (upper_bound(v.begin(), v.end(), a) - v.begin());

        if(right > left) cout << a + 1 << "\n";
        else if(left > right) cout << a - 1 << "\n";
        else cout << 0 << "\n";
    }
    return 0;
}

// ===================== ⚡ Optimized =====================
// Fix: when #(v < a) == #(v > a) > 0, printing 0 can lose points; b = a+1 (or a-1) always takes one whole side.
// To submit: replace the body of your while(t--) loop with optimized::solve().
namespace optimized {
void solve() {
    int n;
    long long a;
    cin >> n >> a;
    vector<long long> v(n);
    for (auto &x : v) cin >> x;
    long long left = lower_bound(v.begin(), v.end(), a) - v.begin();
    long long right = v.end() - upper_bound(v.begin(), v.end(), a);
    cout << (right >= left ? a + 1 : a - 1) << "\n";
}
}

/*
💭 First Idea: Count marbles below and above a; pick a+1 or a-1 for the bigger side, 0 on a tie.
🧩 Key Property / Invariant: Bob at a+1 wins every marble > a, at a-1 every marble < a; he can never beat Alice on both sides.
✅ Key insight: Answer a+1 if right >= left else a-1; a tie still has points to grab.
🔁 Recognition cue for next time: "Pick a point closest to most items vs a fixed opponent" -> stand right next to the opponent on the heavier side.
⏱  Speed fix for next time: Test a tie with marbles on both sides (a=5, v=[4,6]: b=0 scores 0, b=6 scores 1).
🛠  Review: wrong when left == right > 0 (prints 0, which can score less); yours O(n) -> optimized O(n).
*/
