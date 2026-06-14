#include <bits/stdc++.h>
using namespace std;



void solve(){
    int n;
    cin >> n;

    int mx = INT_MIN, mn = INT_MAX;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        mx = max(mx, x);
        mn = min(mn, x);
    }

    cout << mx - mn + 1 << "\n";
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
💭 First Idea
🧩 Key Property / Invariant
✅ Key insight
🔁 Recognition cue for next time
⏱  Speed fix for next time
*/