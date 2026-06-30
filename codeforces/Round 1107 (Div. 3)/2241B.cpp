#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/**/

void solve(){
    ll x;
    cin >> x;

    ll d = to_string(x).size();

    int y = 1;

    for(int i = 0; i < d; i++) y *= 10;
    y++;

    cout << y << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}
