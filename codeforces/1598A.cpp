#include <bits/stdc++.h>
using namespace std;

/**/

void solve(){
    int n;
    cin >> n;

    vector<string> edges(2);
    cin >> edges[0] >> edges[1];

    vector<vector<int>> visited(2, vector<int>(n, 0));
    queue<pair<int,int>> q;
    vector<pair<int,int>> directions = {
        {0,1},
        {1,0},
        {0,-1},
        {-1,0},
        {1,1},
        {1,-1},
        {-1,-1},
        {-1,1}
    };

    q.push({0,0});
    visited[0][0] = 1;
    
    while(!q.empty()){
        int sz = q.size();

        for(int x = 0; x < sz; x++){
            auto [i,j] = q.front();
            q.pop();

            if(i == 1 && j == n - 1){
                cout << "YES\n";
                return;
            }

            for(const auto& [di, dj] : directions){
                int ni = i + di;
                int nj = j + dj;

                if(ni < 0 || ni >= 2 || nj < 0 || nj >= n) continue;
                if(edges[ni][nj] == '1') continue;
                if(visited[ni][nj]) continue;

                visited[ni][nj] = 1;
                q.push({ni,nj});
            }
        }
    }
    cout << "NO\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}

/*
💭 First Idea
first idea was DFS and it works but BFS was more intuitive for me because i solved similar patterns like these 
before

🧩 Key Property / Invariant
only push safe cells and skip over the unsafe ones
if a cell is visited, i dont need to visit it again
if i reach cell 1,n-1 then i can output yes

✅ Key insight
vector<string> edges(2) works like a 2D char grid:
edges[row][col].
The input rows are strings, not separated integers.

🔁 Recognition cue for next time
If the problem asks:
"Can I reach from start to target?"
and movement directions are given,
think BFS/DFS on grid.

⏱  Speed fix for next time

*/