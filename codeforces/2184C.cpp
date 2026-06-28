#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    
    long long div = 1;

    for(int res = 0; div <= n; res++, div *= 2){
        long long high = n / div;
        long long low = (n + div - 1) / div;

        if(high == k || low == k){
            cout << res << "\n";
            return;
        }
    }

    cout << -1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}
