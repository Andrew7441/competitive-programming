#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;

    vector<ll> a(n);
    for(ll& i : a) cin >> i;

    vector<int> ops;
    bool flipped = false;

    for(int i = n - 1; i >= 0; i--){
        bool isPositive = (a[i] > 0);

        if(flipped) isPositive = !isPositive;

        if(isPositive){
            flipped = !flipped;
            ops.push_back(i + 1);
        }
    }
    
    cout << ops.size() << '\n';
    for(int& i  : ops) cout << i << " ";
    cout << '\n';
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