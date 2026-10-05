// Rosalind CC — Connected Components (count components of an undirected graph)
// https://rosalind.info/problems/cc/
// Topic: graphs | Tags: dfs, connected-components
// Complexity (yours): O(n + m) time, O(n + m) space
#include <bits/stdc++.h>
using namespace std;

/*https://rosalind.info/problems/cc/*/

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited){
    if(visited[node]) return;

    visited[node] = true;

    for(int& nei : adj[node]){
        if(!visited[nei]){
            dfs(nei, adj, visited);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<vector<int>> adj(n + 1);
    vector<bool> visited(n + 1, false);
    int ans = 0;

    for(int i = 1; i <= k; i++){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            ans++;
            dfs(i, adj, visited);
        }
    }

    cout << ans;


    return 0;
}

/*
💭 First Idea: for every unvisited vertex start a DFS and count how many DFS calls start from the outer loop.
🧩 Key Property / Invariant: one DFS marks exactly one whole component.
✅ Key insight: #components = #times the outer loop finds an unvisited vertex.
🔁 Recognition cue for next time: "how many groups / islands / components" -> DFS/BFS from each unvisited node, or DSU.
⏱  Speed fix for next time: DSU (union-find) avoids building adjacency lists when you only need the count.
🛠  Review: correct (Rosalind sample -> 3); Already optimal O(n + m).
*/
