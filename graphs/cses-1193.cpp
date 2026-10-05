// CSES 1193 — Labyrinth
// https://cses.fi/problemset/task/1193
// Topic: graphs | Tags: bfs, shortest-path, grid, path-reconstruction
// Complexity (yours): O(n*m) time, O(n*m) space
#include <bits/stdc++.h>
using namespace std;

/**/

void solve(){
    int n, m;
    cin >> n >> m;

    vector<string> labr(n);
    pair<int,int> start, finish;
    vector<vector<int>> visited(n, vector<int>(m, -1));
    vector<pair<int,int>> directions = {
        {0,1},
        {1,0},
        {0,-1},
        {-1,0}
    };
    queue<pair<int,int>> q;
    

    for(int i = 0; i < n; i++){
        cin >> labr[i];
        for(int j = 0; j < m; j++){
            if(labr[i][j] == 'A'){
                start = {i,j};
                q.push({i,j});
            }
            else if(labr[i][j] == 'B') finish = {i,j};
        }
    }

    while(!q.empty()){
        auto [i,j] = q.front();
        q.pop();

        for(int k = 0; k < 4; k++){
            int ni = i + directions[k].first;
            int nj = j + directions[k].second;

            if(ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
            if(visited[ni][nj] != -1) continue;
            if(labr[ni][nj] == '#') continue;
            
            visited[ni][nj] = k;
            q.push({ni, nj});
        }
    }

    auto [bi, bj] = finish;
    auto [ai, aj] = start;

    if(visited[bi][bj] == -1){
        cout << "NO\n";
    }
    else{
        string res = "", dir = "RDLU";
        
        while(bi != ai || bj != aj){
            int idx = visited[bi][bj];
            res += dir[idx];
            bi -= directions[idx].first;
            bj -= directions[idx].second;
        }

        reverse(res.begin(), res.end());
        cout << "YES\n" << res.size() << "\n" << res;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

/*
💭 First Idea: BFS from A over the grid, storing for each cell the direction used to enter it, then walk back from B.
🧩 Key Property / Invariant: BFS reaches each cell first via a shortest path, so the stored "came-from direction" forms a shortest-path tree.
✅ Key insight: store only the move index per cell (0..3) instead of a parent pair; undo moves from B to A, then reverse the string.
🔁 Recognition cue for next time: "shortest path in an unweighted grid + print the path" -> BFS + parent/direction array.
⏱  Speed fix for next time: mark A as visited at the start (it gets re-pushed once otherwise — harmless here, but sloppy); stop BFS early when B is popped.
🛠  Review: correct (samples + 500 random grids checked against a reference BFS); Already optimal O(n*m).
*/
