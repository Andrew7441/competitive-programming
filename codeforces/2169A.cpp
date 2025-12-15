#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//https://codeforces.com/contest/2169/problem/A Alice and Bob

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        ll a;
        cin >> n >> a;
        vector<ll> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];

        int left = lower_bound(v.begin(), v.end(), a) - v.begin();
        int right = n - (upper_bound(v.begin(), v.end(), a) - v.begin());

        if(right > left) cout << a + 1 << "\n";
        else if(left > right) cout << a - 1 << "\n";
        else cout << 0 << "\n";
    }
    return 0;
}
