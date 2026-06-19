#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    ll ans = 0;
    ll previousOdd = 0;

    for (int i = 1; i <= n; i += 2) {
        ll keep = a[i];

        if (i > 1) {
            keep = min(keep, a[i - 1] - previousOdd);
        }

        if (i < n) {
            keep = min(keep, a[i + 1]);
        }

        ans += a[i] - keep;
        previousOdd = keep;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) solve();
}
