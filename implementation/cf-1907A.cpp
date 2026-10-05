// Codeforces 1907A — Rook
// https://codeforces.com/problemset/problem/1907/A
// Topic: implementation
// Complexity (yours): O(1) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin >> s;

    char col = s[0];
    char row = s[1];
    
    for(int i = 1; i <= 8; i++){
        if(i != (row - '0')){
            cout << col << i << "\n";
        }
    }
    for(char l = 'a'; l <= 'h'; l++){
        if(l != col){
            cout << l << row << "\n";
        }
    }
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
💭 First Idea: Print all cells in the same column and the same row except the rook's own.
🧩 Key Property / Invariant: A rook moves along its row and column only.
✅ Key insight: 14 cells always: 7 in the column + 7 in the row.
🔁 Recognition cue for next time: 'All moves of a chess piece' -> enumerate its lines.
⏱  Speed fix for next time: Correct as is.
🛠  Review: correct; Already optimal.
*/
