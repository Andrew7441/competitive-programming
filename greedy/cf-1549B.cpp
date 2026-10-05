// Codeforces 1549B — Gregor and the Pawn Game
// https://codeforces.com/problemset/problem/1549/B
// Topic: greedy
// Complexity (yours): O(n) per test
#include <bits/stdc++.h>
using namespace std;

/**/

void solve(){
    int n;
    cin >> n;

    string s,g;
    cin >> s >> g;

    int res = 0;

    for(int i = 0; i < (int)    s.size(); i++){
        if(g[i] == '0') continue;

        if(s[i] == '0'){
            res++;
            s[i] = '2'; //occupied
        }
        else if(i > 0 && s[i-1] == '1'){
            res++;
            s[i - 1] = '2';
        }
        else if(i + 1 < n && s[i + 1] == '1'){
            res++;
            s[i + 1] = '2';
        }
    }
    cout << res << '\n';
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
💭 First Idea: For each Gregor pawn left to right: go straight if empty, else capture left, else capture right.
🧩 Key Property / Invariant: Processing left to right, taking the leftmost available target never hurts later pawns.
✅ Key insight: Mark used cells ('2') so no enemy cell is reached twice.
🔁 Recognition cue for next time: Left-to-right matching where each item can take i−1, i, i+1 → greedy leftmost first.
⏱  Speed fix for next time: None needed.
🛠  Review: correct; O(n) — Already optimal.
*/
