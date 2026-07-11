#include <bits/stdc++.h>
using namespace std;

/**/

void solve(){
    int n, t;
    cin >> n >> t;

    vector<int> a(n + 1);
    for(int i = 1; i < n; i++){
        cin >> a[i];
    }

    int position = 1;

    while(position < t){
        position += a[position];
    }

    cout << (position == t ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

/*
💭 First Idea
🧩 Key Property / Invariant
✅ Key insight
🔁 Recognition cue for next time
⏱  Speed fix for next time
*/