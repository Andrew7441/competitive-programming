// Codeforces 1535A — Fair Playoff
// https://codeforces.com/problemset/problem/1535/A
// Topic: implementation | Tags: sorting
// Complexity (yours): O(1) per test
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        vector<int> a(4);
        for(int i = 0; i < 4; i++){
            cin >> a[i];
        }
        int max1 = max(a[0], a[1]);
        int max2 = max(a[2], a[3]);

        int top[2] = {max1, max2};
        sort(top,top+2,greater<int>());

        int skills[4] = {a[0], a[1], a[2], a[3]};
        sort(skills,skills+4, greater<int>());

        if(top[0] == skills[0] && top[1] == skills[1]){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }

    return 0;
}

/*
💭 First Idea: Compare the two semifinal winners with the top-2 skills overall.
🧩 Key Property / Invariant: The final is fair iff the two strongest players are in different semifinal pairs.
✅ Key insight: Equivalently: min(max(s1,s2), max(s3,s4)) > max(min(s1,s2), min(s3,s4)).
🔁 Recognition cue for next time: "Tournament fair?" → check the top 2 overall are the two winners.
⏱  Speed fix for next time: One-liner: cout << (min(max(a,b),max(c,d)) > max(min(a,b),min(c,d)) ? "YES" : "NO");
🛠  Review: correct; O(1) — Already optimal.
*/
