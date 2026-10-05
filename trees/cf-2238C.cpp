// Codeforces 2238C — Village Guilds
// https://codeforces.com/problemset/problem/2238/C
// Topic: trees | Tags: graphs, dynamic-programming
// Complexity (yours): O(n) time, O(n) space (recursion depth up to n)
#include <bits/stdc++.h>
using namespace std;

/*https://codeforces.com/problemset/problem/2238/C*/


vector<vector<int>> adj;
long long ans;

int dfs(int v, int d){
    int mx1 = d, mx2 = -1;

    for(int child : adj[v]){
        int got = dfs(child, d + 1);

        if(got > mx1){
            mx2 = mx1;
            mx1 = got;
        }
        else if(got > mx2){
            mx2 = got;
        }
    }

    if(mx2 > d) ans += mx2 - d;

    return mx1;
}

void solve(){
    int n;
    cin >> n;

    adj.assign(n + 1, {});
    ans = n;

    for(int i = 2; i <= n; i++){
        int p;
        cin >> p;
        adj[p].push_back(i);
    }

    dfs(1, 0);

    cout << ans << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}

/*
💭 First Idea: Count each guild at its lowest owner: v owns depth D if the nodes at depth D in subtree(v) lie in >= 2 child subtrees.
🧩 Key Property / Invariant: guild(v, h) equals guild(child, h-1) when only one child reaches that depth, so it is not new.
✅ Key insight: Answer = n (h = 0) + sum over v of (second-largest child max depth - depth(v)).
🔁 Recognition cue for next time: "Count distinct level-sets of subtrees" -> charge each set to the LCA of its nodes.
⏱  Speed fix for next time: Return the max depth from dfs and keep the top two; no sets needed.
🛠  Review: correct; O(n) -> Already optimal (stress-tested vs set brute force; for a 2e5 chain recursion is deep but fine on CF).
*/
