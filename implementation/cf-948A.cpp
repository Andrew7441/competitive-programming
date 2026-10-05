// Codeforces 948A — Protect Sheep
// https://codeforces.com/problemset/problem/948/A
// Topic: implementation | Tags: matrix, constructive
// Complexity (yours): O(r·c) time, O(r·c) space
#include <bits/stdc++.h>
using namespace std;

/**/

void solve(){
    int r, c;
    cin >> r >> c;

    vector<string> grid(r);
    for(int i = 0; i < r; i++){
        cin >> grid[i];
    }

    vector<pair<int,int>> dirs = {
        {0,1},
        {1,0},
        {0,-1},
        {-1,0}
    };

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(grid[i][j] != 'S') continue;

            for(const auto& [di, dj] : dirs){
                int ni = i + di;
                int nj = j + dj;

                if(ni < 0 || ni >= r || nj < 0 || nj >= c) continue;
                if(grid[ni][nj] == 'W'){
                    cout << "No\n";
                    return;
                }
            }
        }
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(grid[i][j] == '.') grid[i][j] = 'D';
        }
    }

    cout << "YES\n";
    for(const string& row : grid){
        cout << row << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

/*
💭 First Idea: If any sheep is adjacent to a wolf → No; else fill every '.' with a dog.
🧩 Key Property / Invariant: A wolf can only reach a sheep through empty cells; dogs block everything.
✅ Key insight: Filling all empty cells with dogs is optimal-enough (minimum not required).
🔁 Recognition cue for next time: "Any valid placement" constructive grid → just block everything.
⏱  Speed fix for next time: Statement asks "Yes"/"No"; you print "YES" — print "Yes" to be safe in case the checker is case-sensitive.
🛠  Review: correct (logic); O(r·c) — Already optimal.
*/
