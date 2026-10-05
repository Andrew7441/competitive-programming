// Codeforces 268A — Games
// https://codeforces.com/problemset/problem/268/A
// Topic: brute-force | Tags: hashing
// Complexity (yours): O(n^2) time, O(n) space
#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/268/A Games

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int res = 0;
    int n;
    cin >> n;
    vector<int> home(n);
    vector<int> guest(n);

    for(int i = 0; i < n; i++){
        cin >> home[i] >> guest[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) continue;

            if(home[i] == guest[j]) res++;
        }
    }

    cout << res << "\n";


    return 0;
}

// ===================== ⚡ Optimized =====================
// O(n + C) instead of O(n^2): count guest colours, then each team adds cnt[home colour].
// (No i==j correction needed: a team's home and guest colours always differ.)
// To submit: replace your main() body with optimized::solve().
namespace optimized {
void solve() {
    int n;
    cin >> n;
    vector<int> h(n), cnt(101, 0);
    for (int i = 0; i < n; i++) {
        int g;
        cin >> h[i] >> g;
        cnt[g]++;
    }
    long long res = 0;
    for (int i = 0; i < n; i++) res += cnt[h[i]];
    cout << res << "\n";
}
}

/*
💭 First Idea: Check every ordered pair (i, j), i != j, where home[i] == guest[j].
🧩 Key Property / Invariant: Each such pair is one game where the host wears its guest uniform.
✅ Key insight: Count guest colours once; each team adds cnt[home[i]].
🔁 Recognition cue for next time: 'Count pairs with a[i] == b[j]' -> frequency counting instead of double loop.
⏱  Speed fix for next time: n <= 30 so brute force is fine; counting is the general tool.
🛠  Review: correct; yours O(n^2) → optimized O(n + C).
*/
