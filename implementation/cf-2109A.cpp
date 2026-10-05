// Codeforces 2109A — It's Time To Duel
// https://codeforces.com/problemset/problem/2109/A
// Topic: implementation | Tags: arrays
// Complexity (yours): O(n) time, O(n) space
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> a(n);
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    if(accumulate(a.begin(),  a.end(), 0) == n){
        cout << "YES\n";
        return;
    }

    for(int i = 0; i < n - 1; i++){
        if(!a[i] && !a[i+1]){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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
💭 First Idea: Someone lies if all reports are 1, or two adjacent players both report 0.
🧩 Key Property / Invariant: n-1 duels give n-1 wins, so not all n players won; every duel has a winner, so neighbours can't both have 0.
✅ Key insight: These two local checks are also sufficient: otherwise winners can always be assigned consistently.
🔁 Recognition cue for next time: "Can these reports be consistent?" -> look for the smallest contradictions (counting + adjacent pairs).
⏱  Speed fix for next time: Counting argument first (n-1 wins vs n players), then adjacent pairs.
🛠  Review: correct; O(n) -> Already optimal.
*/
