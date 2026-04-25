#include <bits/stdc++.h>
using namespace std;

/**/

void solve(){
    int n, k;
    cin >> n >> k;

    map<int, int> mp;

    for(int i = 0; i < k; i++){
        int b, c;
        cin >> b >> c;
        mp[b] += c;
    }

    vector<int> sums;
    int ans = 0;

    for(auto& [k, v] : mp){
        sums.push_back(v);
    }

    sort(sums.rbegin(), sums.rend());

    for(int i = 0; i < min(n, (int)sums.size()); i++){
        ans += sums[i];
    }

    cout << ans << "\n";
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
🧩 Key Property / Invariant
✅ Key insight
🔁 Recognition cue for next time
⏱  Speed fix for next time
*/