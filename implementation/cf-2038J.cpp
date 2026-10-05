// Codeforces 2038J — Waiting for...
// https://codeforces.com/problemset/problem/2038/J
// Topic: implementation
// Complexity (yours): O(n)
#include <bits/stdc++.h>
using namespace std;

/**/

int people = 0, bus = 0;

void solve(){
    char e;
    cin >> e;
    int x;
    cin >> x;

    if(e == 'P') people += x;
    else{
        bus += x;
        if(bus - people > 0){
            cout << "YES\n";
            people = 0;
            bus = 0;
        }else{
            cout << "NO\n";
            people -= bus;
            bus = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while(n--){
        solve();
    }

    return 0;
}

/*
💭 First Idea: Track waiting people; on bus with b seats: YES if b > people, then people = max(0, people - b).
🧩 Key Property / Invariant: Monocarp can board only if seats remain after all other waiting people board.
✅ Key insight: Simulate the queue size with one counter.
🔁 Recognition cue for next time: "Events in order, people board a bus" -> simulation with a running count.
⏱  Speed fix for next time: No need for a 'bus' accumulator: compare b with people directly.
🛠  Review: correct; Already optimal (sum of p_i <= 1e9 fits int).
*/
