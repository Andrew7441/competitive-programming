#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> p(n + 1);
    vector<int> res; 

    for(int i = 2; i <= n; i++) cin >> p[i];

    for(int cur = n; cur != 1; cur = p[cur]){
        res.push_back(cur);
    }

    res.push_back(1);
    reverse(res.begin(), res.end());

    for(int i : res) cout << i << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

/*
💭 First Idea
🧩 Key Property / Invariant
✅ Key insight
🔁 Recognition cue for next time
⏱ Speed fix for next time
*/