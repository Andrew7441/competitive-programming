// Codeforces 2009B — osu!mania
// https://codeforces.com/problemset/problem/2009/B
// Topic: implementation
// Complexity (yours): O(n) per test
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        char ch;
        vector<int> res;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= 4; j++){
                cin >> ch;
                if(ch == '#'){
                    res.push_back(j);
                }
            }
        }

        reverse(res.begin(), res.end());
        for(int i : res){
            cout << i << " ";
        }
        cout << "\n";

    }

    return 0;
}

/*
💭 First Idea: Read rows top to bottom, record the '#' column, print in reverse.
🧩 Key Property / Invariant: Notes are processed bottom row first.
✅ Key insight: Collect then reverse the order.
🔁 Recognition cue for next time: "Process from the bottom" -> read all, output reversed.
⏱  Speed fix for next time: s.find('#') + 1 gives the column directly.
🛠  Review: correct; Already optimal.
*/
