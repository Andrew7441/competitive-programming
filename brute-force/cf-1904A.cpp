// Codeforces 1904A — Forked!
// https://codeforces.com/problemset/problem/1904/A
// Topic: brute-force | Tags: geometry, hashing
// Complexity (yours): O(1) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

/**/

void solve(){
    int a, b;
    cin >> a >> b;

    int xK, yK;
    cin >> xK >> yK;

    int xQ, yQ;
    cin >> xQ >> yQ;

   vector<pair<int,int>> moves {
    {a, b}, {a,-b}, {-a, b}, {-a, -b},
    {b, a}, {b, -a}, {-b, a}, {-b,-a}
   };

   set<pair<int,int>> KingPos;
   set<pair<int,int>> QueenPos;

   for(auto [dx, dy] : moves){
    KingPos.insert({xK + dx, yK + dy});
    QueenPos.insert({xQ + dx, yQ + dy});
   }

   int ans = 0;
   for(auto& p: KingPos){
    if(QueenPos.count(p)) ans++;
   }

   cout << ans << "\n";
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
💭 First Idea: Generate the 8 knight-like moves from king and queen, count positions in both sets.
🧩 Key Property / Invariant: A position attacks the king iff it is one 'move' away from it - the relation is symmetric.
✅ Key insight: Using sets dedups the moves when a == b.
🔁 Recognition cue for next time: 'Positions attacking both X and Y' -> intersect the attack sets of X and Y.
⏱  Speed fix for next time: Correct as is.
🛠  Review: correct; Already optimal.
*/
