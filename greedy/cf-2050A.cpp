// Codeforces 2050A — Line Breaks
// https://codeforces.com/problemset/problem/2050/A
// Topic: greedy | Tags: implementation
// Complexity (yours): O(total length) per test
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;

        vector<string> a(n);

        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        int res = 0;

        for(size_t i = 0; i < a.size(); i++){
            if(a[i].size() <= m){
                res++;
                m -= a[i].size();
            }else{
                break;
            }
        }
        cout << res << '\n';
    }

    return 0;
}

/*
💭 First Idea: Take words from the start while their lengths fit into m.
🧩 Key Property / Invariant: Words must be a prefix, so take greedily until one does not fit.
✅ Key insight: Answer = longest prefix with total length <= m.
🔁 Recognition cue for next time: "Take the first x items within a budget" -> greedy prefix sum.
⏱  Speed fix for next time: Cast size() to int to avoid the signed/unsigned warning.
🛠  Review: correct; Already optimal.
*/
