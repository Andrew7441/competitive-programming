// Codeforces 910A — The Way to Home
// https://codeforces.com/problemset/problem/910/A
// Topic: greedy | Tags: graphs, dynamic-programming
// Complexity (yours): O(n·d) time, O(n) space
// ⚠️ Review: s[ni] / vis[ni] read past the end when i+jumps >= n (UB; aborts under _GLIBCXX_DEBUG); see corrected version below.
#include <bits/stdc++.h>
using namespace std;

/*https://codeforces.com/problemset/problem/910/A*/

void solve(){
    int n, d;
    cin >> n >> d;

    string s;
    cin >> s;

    int ans = 0;
    vector<bool> vis(n, false);
    queue<int> q;

    q.push(0);
    vis[0] = true;

    while(q.size()){
        int sz = q.size();
        
        for(int x = 0; x < sz; x++){
            int i = q.front();
            q.pop();

            if(i == n - 1){
                cout << ans << '\n';
                return;
            }

            for(int jumps = 1; jumps <= d; jumps++){
                int ni = i + jumps;

                if(s[ni] == '1' && !vis[ni]){
                    q.push(ni);
                    vis[ni] = true;
                }
            }
        }
        ans++;
    }

    cout << -1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

// ===================== ⚡ Optimized =====================
// Fixes out-of-bounds s[ni] (ni can reach 2n-3) and is simpler: greedily jump to the farthest lily within d.
// To submit: replace your solve() with this one.
namespace optimized {
void solve() {
    int n, d;
    string s;
    cin >> n >> d >> s;
    int pos = 0, jumps = 0;
    while (pos < n - 1) {
        int nxt = pos;
        for (int j = min(n - 1, pos + d); j > pos; j--)
            if (s[j] == '1') { nxt = j; break; }
        if (nxt == pos) { cout << -1 << '\n'; return; }
        pos = nxt;
        jumps++;
    }
    cout << jumps << '\n';
}
}

/*
💭 First Idea: BFS over positions with jumps 1..d to lilies ('1').
🧩 Key Property / Invariant: Reaching farther is never worse: from a farther lily you can reach everything a nearer one can (and more).
✅ Key insight: Greedy: always jump to the farthest '1' within d; if none, answer −1.
🔁 Recognition cue for next time: "Min jumps with max jump length" → greedy farthest reach (like Jump Game II).
⏱  Speed fix for next time: Always bound-check ni < n before indexing; BFS would be fine with that check.
🛠  Review: wrong (UB: out-of-bounds s[ni] for ni ≥ n, likely passes by luck); yours O(n·d) → optimized O(n·d) greedy, bounds-safe.
*/
