#include <bits/stdc++.h>
using namespace std;

/**/

void solve(){
    int x, y;
    cin >> x >> y;

    if(x % 2 != 0 && y % 2 != 0){
        cout << "NO\n";
    }else if(x % 2 == 0 && y % 2 != 0){
        cout << "YES\n";
    }else if(x % 2 != 0 && y % 2 == 0){
        cout << "YES\n";
    }else if(x % 2 == 0 && y % 2 == 0){
        cout << "YES\n";
    }
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