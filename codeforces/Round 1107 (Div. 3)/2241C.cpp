#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    int runs = 1;

    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) runs++;
    }

    int minwf = (runs == 2 ? 2 : 1);

    cout << minwf << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}
