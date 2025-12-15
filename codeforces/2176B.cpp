#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        int pref_max = a[0];
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            if (pref_max > a[i]) ++ans;        
            pref_max = max(pref_max, a[i]);
        }

        cout << ans << '\n';
    }
    return 0;
}
