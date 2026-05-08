#include <bits/stdc++.h>
using namespace std;

/**/

void solve(){
    int n;
    cin >> n;

    vector<int> cnt(100, 0);

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        cnt[x]++; 
    }   

    bool f = true;

    for(int i = 1; i < 100; i++){
        if(cnt[i] > cnt[i-1]){
            f = false;
            break;
        }
    }

    cout << (f ? "YES\n" : "NO\n");
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