#include <bits/stdc++.h>
using namespace std;

/* https://codeforces.com/problemset/problem/115/A */

void solve(){
    int n;
    cin >> n;  

    vector<int> p(n + 1);
    int ans = 0;

    for(int i = 1; i <= n; i++){
        cin >> p[i];
    }

    for(int i = 1; i <= n; i++){
        int depth = 0;
        int cur = i;

        while(cur != -1){
            depth++;
            cur = p[cur];
        }

        ans = max(ans, depth);
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
