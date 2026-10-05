// Codeforces 1989A — Catch the Coin
// https://codeforces.com/problemset/problem/1989/A
// Topic: math
// Complexity (yours): O(1) per test
#include <bits/stdc++.h>
using namespace std;

void solve(){

    int x, y;
    cin >> x >> y;

    if(y < -1){
        cout << "NO\n";
    }else{
        cout << "YES\n";
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
💭 First Idea: Answer YES iff y >= -1.
🧩 Key Property / Invariant: On move t the coin is at (x, y-(t-1)); catchable iff max(|x|, |y-t+1|) <= t.
✅ Key insight: For large t this holds iff y-t+1 >= -t, i.e. y >= -1 (x never matters).
🔁 Recognition cue for next time: Chasing a falling object on a grid with king moves -> compare vertical distance to time.
⏱  Speed fix for next time: Draw 2-3 small cases to spot that only y matters.
🛠  Review: correct; Already optimal.
*/
