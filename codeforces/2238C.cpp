#include <bits/stdc++.h>
using namespace std;

/*https://codeforces.com/problemset/problem/2238/C*/


vector<vector<int>> adj;
long long ans;

int dfs(int v, int d){
    int mx1 = d, mx2 = -1;

    for(int child : adj[v]){
        int got = dfs(child, d + 1);

        if(got > mx1){
            mx2 = mx1;
            mx1 = got;
        }
        else if(got > mx2){
            mx2 = got;
        }
    }

    if(mx2 > d) ans += mx2 - d;

    return mx1;
}

void solve(){
    int n;
    cin >> n;

    adj.assign(n + 1, {});
    ans = n;

    for(int i = 2; i <= n; i++){
        int p;
        cin >> p;
        adj[p].push_back(i);
    }

    dfs(1, 0);

    cout << ans << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}
