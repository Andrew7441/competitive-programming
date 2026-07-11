#include <bits/stdc++.h>
using namespace std;

/**/

void solve(){
    vector<string> endings = {"00", "25", "50", "75"};
    string s;
    cin >> s;

    int n = s.size();
    int ans = n;

    for (string ending : endings) {
        for (int j = n - 1; j >= 0; j--) {
            if (s[j] != ending[1]) continue;

            for (int i = j - 1; i >= 0; i--) {
                if (s[i] == ending[0]) {
                    int deletionsAfter = n - 1 - j;
                    int deletionsBetween = j - i - 1;

                    ans = min(ans, deletionsAfter + deletionsBetween);
                    break;
                }
            }
        }
    }

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
⏱  Speed fix for next time
*/