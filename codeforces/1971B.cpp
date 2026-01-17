#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;

        string res = s;
        sort(res.begin(), res.end());

        if(res == s) reverse(res.begin(), res.end());

        if(res == s) cout << "NO\n";
        else cout << "YES\n" << res << "\n";
    }

    return 0;
}