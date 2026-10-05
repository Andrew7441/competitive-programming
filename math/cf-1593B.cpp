// Codeforces 1593B — Make it Divisible by 25
// https://codeforces.com/problemset/problem/1593/B
// Topic: math | Tags: greedy, strings
// Complexity (yours): O(4·len^2) per test (len ≤ 19)
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
💭 First Idea: Try each ending 00/25/50/75: pick the rightmost matching last digit, then the nearest first digit to its left.
🧩 Key Property / Invariant: A number is divisible by 25 iff its last two digits are 00, 25, 50 or 75.
✅ Key insight: Deletions = digits after the chosen last digit + digits between the two chosen digits.
🔁 Recognition cue for next time: Divisibility by 25/4/8 etc. → only the last few digits matter.
⏱  Speed fix for next time: Breaking after the first (rightmost) j that works per ending is enough; the full loop is fine since len ≤ 19.
🛠  Review: correct; O(len^2) — Already optimal for constraints.
*/