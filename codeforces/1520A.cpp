#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n; 
    cin >> n;

    string s;
    cin >> s;

    char prev = s[0];
    array<bool,26> finished{};


    for(int i = 1; i < n; i++){
        if(prev == s[i]) continue;

        finished[prev - 'A'] = true; 

        if(finished[s[i] - 'A']){
            cout << "NO\n";
            return;
        }
        prev = s[i];
    }
    cout << "YES\n";
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