// Codeforces 1829E — The Lakes
// https://codeforces.com/problemset/problem/1829/E
// Topic: graphs | Tags: matrix, dfs
// Complexity (yours): O(nm) time, O(nm) space (recursion depth up to nm)
#include <bits/stdc++.h>
using namespace std;

/*https://codeforces.com/problemset/problem/1829/E*/

int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited){
    int n = grid.size(), m = grid[0].size();
    int ans = 0;

    if(i < 0 || i >= n || j < 0 || j >= m) return 0;
    if(visited[i][j]) return 0;
    if(!grid[i][j]) return 0;

    visited[i][j] = true;
    ans += grid[i][j];

    ans += dfs(i, j + 1, grid, visited);
    ans += dfs(i + 1, j, grid, visited);
    ans += dfs(i, j - 1, grid, visited);
    ans += dfs(i - 1, j, grid, visited);

    return ans;
}

void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m, 0));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int ans = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] != 0){
                ans = max(ans, dfs(i, j, grid, visited));
            }
        }
    }

    cout << ans << '\n';
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
// Same O(nm), but iterative flood fill: recursion depth can reach n*m = 1e6 (fine on CF's big stack, crashes locally).
// To submit: replace your solve() with this one.
namespace optimized {
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m));
    for (auto& row : g) for (int& x : row) cin >> x;
    long long best = 0;
    const int dr[4] = {0, 1, 0, -1}, dc[4] = {1, 0, -1, 0};
    vector<pair<int,int>> st;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (!g[i][j]) continue;
            long long sum = 0;
            st.push_back({i, j});
            sum += g[i][j]; g[i][j] = 0;            // mark visited by zeroing
            while (!st.empty()) {
                auto [r, c] = st.back(); st.pop_back();
                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d], nc = c + dc[d];
                    if (nr < 0 || nr >= n || nc < 0 || nc >= m || !g[nr][nc]) continue;
                    sum += g[nr][nc]; g[nr][nc] = 0;
                    st.push_back({nr, nc});
                }
            }
            best = max(best, sum);
        }
    cout << best << '\n';
}
}

/*
💭 First Idea: Recursive DFS flood fill summing depths, keep the maximum component sum.
🧩 Key Property / Invariant: Each cell is visited once; components are 4-connected nonzero cells.
✅ Key insight: Connected components on a grid = flood fill (DFS/BFS).
🔁 Recognition cue for next time: 'Max sum / size of connected region in a grid' -> flood fill.
⏱  Speed fix for next time: Use an explicit stack (or BFS) to avoid deep recursion; zero cells to mark visited.
🛠  Review: correct (recursion depth up to 10^6 is OK on CF's large stack); yours O(nm) -> optimized O(nm) iterative, safe stack.
*/
