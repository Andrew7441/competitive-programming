// Codeforces 2184C — Huge Pile
// https://codeforces.com/problemset/problem/2184/C
// Topic: math | Tags: brute-force
// Complexity (yours): O(log n) time, O(1) space
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    
    long long div = 1;

    for(int res = 0; div <= n; res++, div *= 2){
        long long high = n / div;
        long long low = (n + div - 1) / div;

        if(high == k || low == k){
            cout << res << "\n";
            return;
        }
    }

    cout << -1 << "\n";
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
💭 First Idea: At depth d every pile is floor(n/2^d) or ceil(n/2^d); return the first depth where k appears.
🧩 Key Property / Invariant: Floor/ceil halving keeps all piles at depth d within {floor(n/2^d), ceil(n/2^d)}.
✅ Key insight: Check those two values for d = 0..log n; if k never appears the answer is -1.
🔁 Recognition cue for next time: "Repeated floor/ceil halving" -> values on each level differ by at most 1.
⏱  Speed fix for next time: Know the floor/ceil halving property; then it is a 30-step loop.
🛠  Review: correct (stress-tested vs BFS); O(log n) -> Already optimal.
*/
