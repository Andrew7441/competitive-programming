#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int &x : p) cin >> x;

    int l = 0;
    while (l < n - 1 && p[l] >= *max_element(p.begin() + l, p.end())) l++;

    if (l < n - 1) {
        int r = l;
        int max_val = p[l];
        for (int i = l; i < n; i++) {
            if (p[i] >= max_val) {
                max_val = p[i];
                r = i;
            }
        }
        reverse(p.begin() + l, p.begin() + r + 1);
    }

    for (int x : p) cout << x << " ";
    cout << "\n";
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