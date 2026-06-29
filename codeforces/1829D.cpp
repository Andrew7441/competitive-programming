#include <bits/stdc++.h>
using namespace std;

/*

bool canMake(int n, int m){
    if(n == m) return true;
    if(n < m || n % 3 != 0) return false;

    return canMake(n / 3, m) || canMake(2 * n / 3, m);
}

void solve(){
    int n, m;
    cin >> n >> m;

    cout << (canMake(n,m) ? "YES" : "NO") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}
*/

//BFS solution

void solve(){
    int n, m;
    cin >> n >> m;

    queue<int> q;
    q.push(n);

    while(!q.empty()){
        int x = q.front();
        q.pop();

        if(x == m){
            cout << "YES\n";
            return;
        }else if(x < m || x % 3 != 0){
            continue;
        }

        q.push(x / 3);
        q.push(x * 2 / 3);
    }

    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}