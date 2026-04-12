#include <bits/stdc++.h>
using namespace std;

/**/

void solve(){
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int cnt0 = count(s.begin(), s.end(), '0');
    int cnt1 = count(s.begin(), s.end(), '1');
    int cnt2 = count(s.begin(), s.end(), '2');

    string ans(n, '+');

    for(int i = 0; i < n; i++){
        if(i < cnt0 + cnt2 || i >= n - cnt1 - cnt2) ans[i] = '?';
        if(i < cnt0 || i >= n - cnt1 || k == n) ans[i] = '-';
    }

    cout << ans << "\n";
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