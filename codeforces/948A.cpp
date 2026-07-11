#include <bits/stdc++.h>
using namespace std;

/**/

void solve(){
    int r, c;
    cin >> r >> c;

    vector<string> grid(r);
    for(int i = 0; i < r; i++){
        cin >> grid[i];
    }

    vector<pair<int,int>> dirs = {
        {0,1},
        {1,0},
        {0,-1},
        {-1,0}
    };

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(grid[i][j] != 'S') continue;

            for(const auto& [di, dj] : dirs){
                int ni = i + di;
                int nj = j + dj;

                if(ni < 0 || ni >= r || nj < 0 || nj >= c) continue;
                if(grid[ni][nj] == 'W'){
                    cout << "No\n";
                    return;
                }
            }
        }
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(grid[i][j] == '.') grid[i][j] = 'D';
        }
    }

    cout << "YES\n";
    for(const string& row : grid){
        cout << row << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
