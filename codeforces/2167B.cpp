#include <bits/stdc++.h>
using namespace std;

/**/

void solve(){
    int n;
    cin >> n;

    string s, t;
    cin >> s >> t;

    vector<int> m1(26), m2(26);

    for(char& c : s){
        m1[c - 'a']++;
    }
    for(char& c : t){
        m2[c - 'a']++;
    }

    for(int i = 0; i < 26; i++){
        if(m1[i] != m2[i]){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while(q--){
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