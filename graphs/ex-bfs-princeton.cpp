// Algs4 (Princeton) BreadthFirstPaths — single-source shortest paths in an undirected graph via BFS
// https://algs4.cs.princeton.edu/41graph/BreadthFirstPaths.java.html
// Topic: graphs | Tags: bfs, shortest-path, path-reconstruction
// Complexity (yours): — (stub)
// ⚠️ Review: unfinished — empty stub; see implemented version below.
#include <bits/stdc++.h>
using namespace std;

/*
https://algs4.cs.princeton.edu/41graph/BreadthFirstPaths.java.html

*/

void solve(){
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}

// ===================== ⚡ Optimized =====================
// C++ port of algs4 BreadthFirstPaths: marked[], edgeTo[], distTo[]; hasPathTo / distTo / pathTo.
// O(V + E) BFS, pathTo O(path length).
// Input (algs4 format): V E, then E undirected edges "v w", then source s.
// To submit: call optimized::solve() from main.
namespace optimized {
class BreadthFirstPaths {
    vector<bool> marked;     // marked[v] = is there an s-v path?
    vector<int> edgeTo;      // edgeTo[v] = previous vertex on a shortest s-v path
    vector<int> dist;        // dist[v]   = number of edges on a shortest s-v path
    int s;
public:
    BreadthFirstPaths(const vector<vector<int>>& adj, int s)
        : marked(adj.size(), false), edgeTo(adj.size(), -1), dist(adj.size(), INT_MAX), s(s) {
        queue<int> q;
        marked[s] = true;
        dist[s] = 0;
        q.push(s);
        while(!q.empty()){
            int v = q.front(); q.pop();
            for(int w : adj[v]){
                if(marked[w]) continue;
                marked[w] = true;
                edgeTo[w] = v;
                dist[w] = dist[v] + 1;
                q.push(w);
            }
        }
    }
    bool hasPathTo(int v) const { return marked[v]; }
    int distTo(int v) const { return dist[v]; }
    vector<int> pathTo(int v) const {
        if(!hasPathTo(v)) return {};
        vector<int> path;
        for(int x = v; x != s; x = edgeTo[x]) path.push_back(x);
        path.push_back(s);
        reverse(path.begin(), path.end());
        return path;
    }
};

void solve(){
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj(V);
    for(int i = 0; i < E; i++){
        int v, w;
        cin >> v >> w;
        adj[v].push_back(w);
        adj[w].push_back(v);
    }
    int s;
    cin >> s;
    BreadthFirstPaths bfs(adj, s);
    for(int v = 0; v < V; v++){
        if(!bfs.hasPathTo(v)){ cout << s << " to " << v << " (-): not connected\n"; continue; }
        cout << s << " to " << v << " (" << bfs.distTo(v) << "): ";
        auto p = bfs.pathTo(v);
        for(size_t i = 0; i < p.size(); i++) cout << (i ? "-" : "") << p[i];
        cout << "\n";
    }
}
}

/*
💭 First Idea: (stub) — port algs4 BreadthFirstPaths: BFS from s recording marked/edgeTo/distTo.
🧩 Key Property / Invariant: when w is first marked from v, dist[w] = dist[v] + 1 is final, and edgeTo[] forms a shortest-path tree rooted at s.
✅ Key insight: storing just the parent (edgeTo) is enough to rebuild any shortest path by walking back to s.
🔁 Recognition cue for next time: "shortest path in edges + print the path" -> BFS + parent array.
⏱  Speed fix for next time: mark on push (not pop) so each vertex enters the queue once.
🛠  Review: unfinished (empty stub); implemented version O(V + E).
*/
