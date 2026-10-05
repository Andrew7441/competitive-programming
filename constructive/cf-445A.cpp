// Codeforces 445A — DZY Loves Chessboard
// https://codeforces.com/problemset/problem/445/A
// Topic: constructive | Tags: matrix
// Complexity (yours): stub - nothing implemented
// ⚠️ Review: stub only prints HelloWorld; see corrected version below.
#include <bits/stdc++.h>
using namespace std;

void solve() {
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "HelloWorld";

    return 0;
}

// ===================== ⚡ Optimized =====================
// Finished solution, O(n*m): colour the board like a chessboard by (i+j) parity;
// adjacent cells always differ in parity, so they get different colours. '-' stays '-'.
// To submit: replace your solve() with this one and call it from main().
namespace optimized {
void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < m; j++)
            if (row[j] == '.') row[j] = ((i + j) % 2 == 0) ? 'B' : 'W';
        cout << row << "\n";
    }
}
}

/*
💭 First Idea: Not started (stub prints HelloWorld).
🧩 Key Property / Invariant: Adjacent cells always have different (i+j) parity.
✅ Key insight: Chessboard colouring by (i+j)%2; bad cells '-' just stay '-'.
🔁 Recognition cue for next time: 'Adjacent cells must differ' on a grid -> chessboard / bipartite colouring.
⏱ Speed fix for next time: Grid adjacency constraint -> try (i+j) parity first.
🛠  Review: unfinished; optimized O(n*m) solution added.
*/