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