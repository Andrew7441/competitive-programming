// Codeforces 115A — Party
// https://codeforces.com/problemset/problem/115/A
// Topic: trees | Tags: graphs, dfs
// Complexity (yours): O(n^2) time worst case (chain), O(n) space
#include <bits/stdc++.h>
using namespace std;

/* https://codeforces.com/problemset/problem/115/A */

void solve(){
    int n;
    cin >> n;  

    vector<int> p(n + 1);
    int ans = 0;

    for(int i = 1; i <= n; i++){
        cin >> p[i];
    }

    for(int i = 1; i <= n; i++){
        int depth = 0;
        int cur = i;

        while(cur != -1){
            depth++;
            cur = p[cur];
        }

        ans = max(ans, depth);
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// ===================== ⚡ Optimized =====================
// O(n) instead of O(n^2): memoize each employee's depth so every chain is walked once.
// To submit: replace your solve() with this one.
namespace optimized {
void solve() {
    int n;
    cin >> n;
    vector<int> p(n + 1), depth(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> p[i];
    function<int(int)> get = [&](int v) -> int {
        if (v == -1) return 0;
        if (depth[v]) return depth[v];
        return depth[v] = 1 + get(p[v]);
    };
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, get(i));
    cout << ans << "\n";
}
}

/*
💭 First Idea: For each employee walk up the manager chain to the root and take the max length.
🧩 Key Property / Invariant: Minimum number of groups = maximum depth of the forest (a chain needs one group per level).
✅ Key insight: Each depth level is a valid group; you cannot do better than the longest chain.
🔁 Recognition cue for next time: 'No one with their boss/ancestor' -> answer is tree height.
⏱  Speed fix for next time: Memoize depth[v] = 1 + depth[p[v]] so each node is computed once.
🛠  Review: correct (n <= 2000 so O(n^2) passes); yours O(n^2) → optimized O(n).
*/
