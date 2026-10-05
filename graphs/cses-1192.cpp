// CSES 1192 — Counting Rooms
// https://cses.fi/problemset/task/1192
// Topic: graphs | Tags: dfs, flood-fill, grid
// Complexity (yours): O(n*m) time, O(n*m) space (recursion depth up to n*m)
#include <bits/stdc++.h>
using namespace std;

/**/

void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& visited){
    int n = grid.size(), m = grid[0].size();

    if(i < 0 || i >= n || j < 0 || j >= m) return;
    if(visited[i][j]) return;
    if(grid[i][j] == '#') return;
    
    visited[i][j] = true;

    dfs(i, j + 1, grid, visited);
    dfs(i + 1, j, grid, visited);
    dfs(i, j - 1, grid, visited);
    dfs(i - 1, j, grid, visited);
}

int solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int ans = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c;
            cin >> c;
            grid[i][j] = c;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '.' && !visited[i][j]){
                ans++;
                dfs(i, j, grid, visited);
            }
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << solve();

    return 0;
}

// ===================== ⚡ Optimized =====================
// Same O(n*m), but iterative (explicit stack) flood fill: recursive dfs can hit depth 10^6
// on a 1000x1000 all-floor grid and segfaults with a default 8 MB stack.
// To submit: replace your solve() with this one.
namespace optimized {
int solve(){
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for(auto& row : g) cin >> row;

    int ans = 0;
    const int di[4] = {0, 1, 0, -1}, dj[4] = {1, 0, -1, 0};
    vector<pair<int,int>> st;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(g[i][j] != '.') continue;
            ans++;
            g[i][j] = '#';                 // mark visited by overwriting the grid
            st.push_back({i, j});
            while(!st.empty()){
                auto [x, y] = st.back(); st.pop_back();
                for(int k = 0; k < 4; k++){
                    int nx = x + di[k], ny = y + dj[k];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m || g[nx][ny] != '.') continue;
                    g[nx][ny] = '#';
                    st.push_back({nx, ny});
                }
            }
        }
    }
    return ans;
}
}

/*
💭 First Idea: count floor cells that start a new recursive DFS flood fill (each start = one room).
🧩 Key Property / Invariant: every floor cell belongs to exactly one connected component; a DFS from an unvisited cell marks its whole room.
✅ Key insight: number of rooms = number of connected components of the grid graph (4-neighbour edges between '.').
🔁 Recognition cue for next time: "count regions / islands / rooms in a grid" -> flood fill (DFS/BFS) or DSU.
⏱  Speed fix for next time: read rows as strings (vector<string>) and mark visited in the grid itself; use an explicit stack to avoid deep recursion.
🛠  Review: correct (passes on CSES's large stack, but segfaults locally at 1000x1000 with 8 MB stack); yours O(n*m) → optimized O(n*m) iterative, stack-safe.
*/
