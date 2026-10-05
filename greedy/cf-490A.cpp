// Codeforces 490A — Team Olympiad
// https://codeforces.com/problemset/problem/490/A
// Topic: greedy | Tags: implementation
// Complexity (yours): O(n) time, O(n) space
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> p, m, s;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == 1){
            p.push_back(i+1);
        }else if(a[i] == 2){
            m.push_back(i+1);
        }else{
            s.push_back(i+1);
        }
    }

    int w = min({p.size(), m.size(), s.size()});

    cout << w << "\n";

    for(int i = 0; i < w; i++){
        cout << p[i] << " " << m[i] << " " << s[i] << "\n";
    }
    

    return 0;
}

/*
💭 First Idea: Bucket indices by skill; number of teams = min bucket size; pair them up.
🧩 Key Property / Invariant: Every team needs one of each skill, so the smallest group limits.
✅ Key insight: answer = min(|1s|, |2s|, |3s|); take indices in any order.
🔁 Recognition cue for next time: 'Form groups needing one of each type' -> min of counts.
⏱  Speed fix for next time: Use vector<int> g[4] indexed by skill.
🛠  Review: correct; Already optimal.
*/
