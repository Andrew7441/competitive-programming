#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin >> s;

    vector<int> a(10);

    for(char& c : s) a[c - '0']++;

    int mx = *max_element(a.begin(), a.end());

    if(mx == 4) cout << -1 << "\n";
    else if(mx == 3) cout << 6 << "\n";
    else cout << 4 << "\n";
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
💭 First Idea
First thought was to simulate operations with a map / on-off state and try toggling bulbs until all become on.

Why that was wrong:
It focuses on the process, but this problem is so small that only the color frequency pattern matters. Simulation is unnecessary and slower to reason about.

🧩 Key Property / Invariant
The exact positions do not matter; only how many times each color appears matters.
There are only 3 real outcomes:
- max frequency 4 -> impossible
- max frequency 3 -> answer 6
- otherwise -> answer 4

✅ Key insight
A color appearing too many times is the only thing that creates trouble, because consecutive operations cannot use the same color.

🔁 Recognition cue for next time
when n is tiny and the statement looks simulation-heavy, check whether the answer depends only on counts / cases instead of actual step-by-step construction.

⏱  Speed fix for next time
List the frequency patterns first:
1111, 1112, 1122, 1123, 1234.
answer now becomes immediate.
*/