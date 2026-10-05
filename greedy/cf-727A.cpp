// Codeforces 727A — Transformation: from A to B
// https://codeforces.com/problemset/problem/727/A
// Topic: greedy | Tags: brute-force, math
// Complexity (yours): O(log b) time, O(log b) space
#include <bits/stdc++.h>
using namespace std;


void solve(){
    int a, b;
    cin >> a >> b;

    vector<int> res;
    res.push_back(b);
    
    while(b > a){
        if(b % 10 == 1){
            b /= 10;
        }
        else if(b % 2 == 0){
            b /= 2;
        }
        else {
            break;
        }
        res.push_back(b);
    }

    if(b != a){
        cout << "NO\n";
        return;
    }

    reverse(res.begin(), res.end());

    cout << "YES\n" << res.size() << "\n";
    for(int& i : res){
        cout << i << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

/*
💭 First Idea: Walk backwards from b: strip a trailing 1 or halve if even, until reaching a.
🧩 Key Property / Invariant: From any b at most one reverse move is valid (ends in 1 → odd, so can't halve; even → can't end in 1).
✅ Key insight: Reverse path is unique, so greedy reverse simulation is exact; then reverse the recorded path.
🔁 Recognition cue for next time: Forward ops ×2 / append digit → reverse them from the target (same trick as 520B).
⏱  Speed fix for next time: None needed.
🛠  Review: correct; O(log b) — Already optimal.
*/
