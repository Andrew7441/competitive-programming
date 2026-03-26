#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; 
    cin >> n;

    string s;
    cin >> s;

    vector<int> f(26,0);

    for(char &i: s){
        f[i-'A']++;
    }

    int solved = 0;
    for(int i = 0; i < 26; i++){
        if(f[i] >= i + 1) solved++;
    }

    cout << solved << "\n";
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