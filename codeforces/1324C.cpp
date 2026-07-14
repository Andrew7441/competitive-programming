#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;

    int last = 0, ans = 0;

    for(size_t i = 0; i < s.size(); i++){
        if(s[i] == 'R'){
            int position = i + 1;
            ans = max(ans, position - last);
            last = position;
        }
    }

    ans = max(ans, (int)s.size() + 1 - last);
    cout << ans << '\n';
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