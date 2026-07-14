#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int longest = 0, current = 0;

    for(char& c : s){
        if(c == '#'){
            current++;
            longest = max(longest, current);
        }
        else {
            current = 0;
        }
    }

    cout << (longest + 1) / 2 << '\n';
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
⏱ Speed fix for next time
*/