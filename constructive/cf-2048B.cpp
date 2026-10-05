// Codeforces 2048B — Kevin and Permutation
// https://codeforces.com/problemset/problem/2048/B
// Topic: constructive | Tags: greedy
// Complexity (yours): O(n) per test
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> p(n + 1, 0);
        int cur = 1;

        for (int i = k; i <= n; i += k) {
            p[i] = cur++;
        }

        for (int i = 1; i <= n; i++) {
            if (p[i] == 0) {
                p[i] = cur++;
            }
        }

        for (int i = 1; i <= n; i++) {
            cout << p[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}

/*
💭 First Idea: Put 1, 2, 3, ... at positions k, 2k, 3k, ...; fill the rest with remaining numbers.
🧩 Key Property / Invariant: Each value v can be the minimum of at most k windows of length k.
✅ Key insight: Placing small values every k positions makes each small value the min of k windows.
🔁 Recognition cue for next time: "Permutation minimizing sum of window minima" -> spread small values k apart.
⏱  Speed fix for next time: Fill positions k,2k,... first, then the gaps in increasing order.
🛠  Review: correct; Already optimal.
*/
