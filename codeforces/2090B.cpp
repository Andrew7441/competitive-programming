#include <bits/stdc++.h>
using namespace std;

/*https://codeforces.com/problemset/problem/2090/B*/

void solve(){
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);

    for(int i = 0; i < n; i++){
        cin >> grid[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '1'){
                bool left = true;
                bool top = true;

                //rows
                for(int col = 0; col < j; col++){
                    if(grid[i][col] == '0') left = false;
                }

                //cols 
                for(int row = 0; row < i; row++){
                    if(grid[row][j] == '0') top = false;
                }

                if(!left && !top){
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}