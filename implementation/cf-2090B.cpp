// Codeforces 2090B — Pushing Balls
// https://codeforces.com/problemset/problem/2090/B
// Topic: implementation | Tags: matrix, prefix-sum
// Complexity (yours): O(n*m*(n+m)) per test
#include <bits/stdc++.h>
using namespace std;

/*https://codeforces.com/problemset/problem/2090/B*/

void solve(){
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);

    for(int i = 0; i < n; i++){
        cin >> grid[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '1'){
                bool left = true;
                bool top = true;

                //rows
                for(int col = 0; col < j; col++){
                    if(grid[i][col] == '0') left = false;
                }

                //cols 
                for(int row = 0; row < i; row++){
                    if(grid[row][j] == '0') top = false;
                }

                if(!left && !top){
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    cout << "YES\n";
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
// O(n*m) instead of O(n*m*(n+m)): precompute "row prefix all 1s" / "column prefix all 1s".
// To submit: replace your solve() with this one.
namespace optimized {
void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for (auto& r : g) cin >> r;
    vector<char> colOk(m, 1);              // colOk[j]: g[0..i-1][j] are all '1'
    for (int i = 0; i < n; i++) {
        bool rowOk = true;                 // g[i][0..j-1] are all '1'
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '1' && !rowOk && !colOk[j]) { cout << "NO\n"; return; }
            if (g[i][j] == '0') rowOk = false, colOk[j] = 0;
        }
    }
    cout << "YES\n";
}
}

/*
💭 First Idea: For each ball, scan left in its row and up in its column for a '0'.
🧩 Key Property / Invariant: A ball got to (i,j) by being pushed: all cells left of it, or all above it, must be balls.
✅ Key insight: Valid iff every ball has a full-1 row prefix or a full-1 column prefix.
🔁 Recognition cue for next time: "Can this grid be produced by pushing from top/left" -> check prefixes of 1s.
⏱  Speed fix for next time: Precompute row/column prefix flags to get O(n*m).
🛠  Review: correct (fits limits); yours O(nm(n+m)) -> optimized O(nm).
*/
