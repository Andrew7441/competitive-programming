#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, q;
    cin >> n >> q;

    vector<long long> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    a[n-1] = max({a[n-1], b[n-1]});
    for(int i = n - 2; i >= 0; i--){
        a[i] = max({a[i], b[i], a[i+1]});
    }

    vector<long long> prefix(n+1, 0);
    for(int i = 0; i < n; i++){
        prefix[i+1] = prefix[i] + a[i];
    }

    while(q--){
        int l, r;
        cin >> l >> r;
        cout << prefix[r] - prefix[l-1] << " ";
    }
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