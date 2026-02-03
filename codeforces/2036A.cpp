#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> a(n);

    for(int& i : a) cin >> i;

    bool perf = true;

    for(int i = 0; i < n - 1; i++){
        if(abs(a[i] - a[i+1]) != 5 && abs(a[i] - a[i+1]) != 7){
            perf = false;
            break;
        }
    }

    if(perf) cout << "YES\n";
    else cout << "NO\n";
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