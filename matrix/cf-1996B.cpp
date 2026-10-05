// Codeforces 1996B — Scale
// https://codeforces.com/problemset/problem/1996/B
// Topic: matrix | Tags: implementation
// Complexity (yours): O(n^2) per test
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        char A[n][n];

        for(auto& row : A){
            for(char& c : row){
                cin >> c;
            }
        }

        for(int i = 0; i < n; i+=k){
            for(int j = 0; j < n; j+=k){
                cout << A[i][j];
            }
            cout << "\n";
        }

    }

    return 0;
}

/*
💭 First Idea: Print every k-th cell starting at (0,0) — each k×k block is uniform.
🧩 Key Property / Invariant: Every k×k block has a single value, so its top-left cell represents it.
✅ Key insight: Sample A[i][j] for i, j multiples of k.
🔁 Recognition cue for next time: "Reduce grid by factor k, blocks guaranteed uniform" -> sample one cell per block.
⏱  Speed fix for next time: Read rows as strings (vector<string>) instead of a VLA char grid.
🛠  Review: correct; Already optimal.
*/
