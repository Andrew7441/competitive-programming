// Rosalind BFS — Breadth-First Search (shortest distances from vertex 1 in a directed graph)
// https://rosalind.info/problems/bfs/
// Topic: graphs | Tags: bfs, shortest-path
// Complexity (yours): unbounded — no visited check, so nodes are re-queued (exponential on DAGs, infinite loop on cycles)
// ⚠️ Review: no visited/distance check before pushing (infinite loop on any cycle, later longer distances overwrite shorter ones) and main reads an extra t not in the input; see corrected version below.
#include <bits/stdc++.h>
using namespace std;

/* https://rosalind.info/problems/bfs/ */

void solve(){
    int n, m;

    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    queue<pair<int,int>> q;
    vector<int> distance(n + 1, -1);

    for(int i = 0; i < m; i++){
        int u, v;

        cin >> u >> v;

        adj[u].push_back(v);
    }

    q.push({1,0});

    while(!q.empty()){
        auto [node, dist] = q.front();
        q.pop();

        distance[node] = dist;

        for(int& nei : adj[node]){
            q.push({nei, dist + 1});
        }
    }

    for(int i = 1; i <= n; i++){
        cout << distance[i] << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}

// ===================== ⚡ Optimized =====================
// O(n + m): set distance when a node is FIRST pushed and never push it again.
// Rosalind input is a single graph "n m" + edges (no test count t).
// To submit: main = read once and call optimized::solve().
namespace optimized {
void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> dist(n + 1, -1);
    queue<int> q;
    dist[1] = 0;
    q.push(1);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : adj[u]){
            if(dist[v] != -1) continue;      // already discovered with a shorter/equal distance
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
    for(int i = 1; i <= n; i++) cout << dist[i] << " \n"[i == n];
}
}

/*
💭 First Idea: BFS from vertex 1 pushing (node, dist) pairs and writing distance when a node is popped.
🧩 Key Property / Invariant: BFS pops nodes in non-decreasing distance order, so the FIRST time a node is discovered is its shortest distance.
✅ Key insight: mark a node visited (dist != -1) when you push it; never push it twice.
🔁 Recognition cue for next time: "shortest path, unweighted graph" -> BFS with a dist[] array initialised to -1 doubling as visited.
⏱  Speed fix for next time: always check visited before pushing; match the exact input format (no t on Rosalind).
🛠  Review: wrong — no visited check (loops forever on 1->2->1, overwrites distances) + reads extra t; yours unbounded → optimized O(n + m).
*/
