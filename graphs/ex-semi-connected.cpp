// Rosalind SC — Semi-Connected Graph
// https://rosalind.info/problems/sc/
// Topic: graphs | Tags: dfs, scc, topological-sort
// Complexity (yours): O(n^2 * (n + m)) per graph (two DFS per pair)
#include <bits/stdc++.h>
using namespace std;

/*https://rosalind.info/problems/sc/

A directed graph is semi-connected if for all pairs of vertices i,j
 there is either a path from i
 to j
 or a path from j
 to i
.

Given: A positive integer k≤20
 and k
 simple directed graphs with at most 103
 vertices each in the edge list format.

Return: For each graph, output "1" if the graph is semi-connected and "-1" otherwise.

Sample Dataset
2

3 2
3 2
2 1

3 2
3 2
1 2
Sample Output
1 -1
*/

bool dfs(int u, int v, vector<vector<int>>& adj, vector<bool>& visited){
    if(u == v) return true;
    if(visited[u]) return false;

    visited[u] = true;

    for(int& nei : adj[u]){
        if(dfs(nei, v, adj, visited)) return true;
    }

    return false;
}

void solve(){
    bool semi = true;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);


    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
    }
    

    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            vector<bool> visited1(n + 1, false);
            vector<bool> visited2(n + 1, false);

            if(!dfs(i,j, adj, visited1) && !dfs(j, i, adj, visited2)) semi = false;
        }

        if(!semi) break;
    }

    cout << (semi ? 1 : -1) << " ";
}

int main()
{
    int k;
    cin >> k;

    while(k--){
        solve();
    }

    return 0;
}

// ===================== ⚡ Optimized =====================
// O(n + m) instead of O(n^2 (n + m)): condense SCCs (Kosaraju). Kosaraju emits SCCs in topological
// order of the condensation DAG; the graph is semi-connected iff every consecutive pair
// (comp i, comp i+1) is joined by an edge (i.e. the DAG has a Hamiltonian path).
// To submit: replace your solve() with this one.
namespace optimized {
void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1), radj(n + 1);
    vector<pair<int,int>> edges(m);
    for(auto& [u, v] : edges){
        cin >> u >> v;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }
    vector<int> order, comp(n + 1, -1);
    vector<bool> vis(n + 1, false);
    function<void(int)> dfs1 = [&](int u){
        vis[u] = true;
        for(int v : adj[u]) if(!vis[v]) dfs1(v);
        order.push_back(u);
    };
    function<void(int, int)> dfs2 = [&](int u, int c){
        comp[u] = c;
        for(int v : radj[u]) if(comp[v] == -1) dfs2(v, c);
    };
    for(int i = 1; i <= n; i++) if(!vis[i]) dfs1(i);
    int C = 0;
    for(int i = n - 1; i >= 0; i--) if(comp[order[i]] == -1) dfs2(order[i], C++);

    vector<bool> linkNext(C, false);                 // edge comp i -> comp i+1 exists?
    for(auto [u, v] : edges) if(comp[v] == comp[u] + 1) linkNext[comp[u]] = true;
    bool semi = true;
    for(int c = 0; c + 1 < C; c++) if(!linkNext[c]) semi = false;
    cout << (semi ? 1 : -1) << " ";
}
}

/*
💭 First Idea: for every pair (i, j) run DFS i->j and j->i; semi-connected iff one succeeds for every pair.
🧩 Key Property / Invariant: inside an SCC all pairs are mutually reachable, so only the order of SCCs matters.
✅ Key insight: semi-connected <=> the SCC condensation DAG has a Hamiltonian path <=> consecutive SCCs in topological order are directly linked.
🔁 Recognition cue for next time: "every pair reachable in at least one direction" -> SCC condensation + topological order check.
⏱  Speed fix for next time: one reachability pass per vertex (O(n (n + m))) is already a big win; SCC + topo is O(n + m).
🛠  Review: correct but slow (two DFS per pair); yours O(n^2 (n + m)) → optimized O(n + m).
*/
