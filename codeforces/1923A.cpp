#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    int l = -1, r = -1, c = 0;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == 1){
            if(l == -1) l = i;
            r = i;
        }
    }

    for(int i = l; i <= r; i++){
        if(a[i] == 0) c++;
    }

    cout << c << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}