#include <bits/stdc++.h>
using namespace std;

/**/

void solve(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int& i : a) cin >> i;

    bool odd = false, even = false;

    for(int& i : a){
        if(i % 2) odd = true;
        else even = true;
    }

    if(even && odd){
        sort(a.begin(), a.end());
    }

    for(int &i: a) cout << i << " ";
    cout << "\n";
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