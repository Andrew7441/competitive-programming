#include <bits/stdc++.h>
using namespace std;

/*https://codeforces.com/problemset/problem/910/A*/

void solve(){
    int n, d;
    cin >> n >> d;

    string s;
    cin >> s;

    int ans = 0;
    vector<bool> vis(n, false);
    queue<int> q;

    q.push(0);
    vis[0] = true;

    while(q.size()){
        int sz = q.size();
        
        for(int x = 0; x < sz; x++){
            int i = q.front();
            q.pop();

            if(i == n - 1){
                cout << ans << '\n';
                return;
            }

            for(int jumps = 1; jumps <= d; jumps++){
                int ni = i + jumps;

                if(s[ni] == '1' && !vis[ni]){
                    q.push(ni);
                    vis[ni] = true;
                }
            }
        }
        ans++;
    }

    cout << -1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
