// Codeforces 1829D — Gold Rush
// https://codeforces.com/problemset/problem/1829/D
// Topic: brute-force | Tags: graphs, math
// Complexity (yours): O(2^(log_3 n)) ~ 3*10^4 states per test, O(same) space
#include <bits/stdc++.h>
using namespace std;

/*

bool canMake(int n, int m){
    if(n == m) return true;
    if(n < m || n % 3 != 0) return false;

    return canMake(n / 3, m) || canMake(2 * n / 3, m);
}

void solve(){
    int n, m;
    cin >> n >> m;

    cout << (canMake(n,m) ? "YES" : "NO") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}
*/

//BFS solution

void solve(){
    int n, m;
    cin >> n >> m;

    queue<int> q;
    q.push(n);

    while(!q.empty()){
        int x = q.front();
        q.pop();

        if(x == m){
            cout << "YES\n";
            return;
        }else if(x < m || x % 3 != 0){
            continue;
        }

        q.push(x / 3);
        q.push(x * 2 / 3);
    }

    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}

/*
💭 First Idea: BFS over all piles reachable by splitting into 1/3 and 2/3 (recursive DFS kept in comments).
🧩 Key Property / Invariant: A pile can only be split while divisible by 3, and n <= 10^7 < 3^15, so depth <= 14.
✅ Key insight: Small depth bounds the tree to < 2^15 nodes, so plain search is fast enough.
🔁 Recognition cue for next time: 'Repeated split by fixed ratio' -> the depth is logarithmic, just search.
⏱  Speed fix for next time: Prune x < m early (you already do); no visited set needed at this size.
🛠  Review: correct; Already optimal.
*/
