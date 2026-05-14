#include <bits/stdc++.h>
using namespace std;

/**/

void solve(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    int open = 0;
    int closed = 0;

    for(char c : s){
        if(c == '(') open++;
        else closed++;
    }

    if(open == closed) cout << "YES\n";
    else cout << "NO\n";
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