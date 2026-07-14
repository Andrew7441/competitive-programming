#include <bits/stdc++.h>
using namespace std;

/**/

bool dfs(int i, int j, vector<vector<int>>& board, vector<vector<bool>>& visited, int cx, int cy){
    int n = board.size();

    if(i < 0 || i >= n || j < 0 || j >= n) return false;
    if(board[i][j] == 1) return false;
    if(visited[i][j]) return false;
    if(i == cx && j == cy) return true;

    visited[i][j] = true;

    bool right = dfs(i, j + 1, board, visited, cx, cy); // right
    bool downR = dfs(i + 1, j + 1, board, visited, cx, cy); // down right
    bool down = dfs(i + 1, j, board, visited, cx, cy); // down
    bool downL = dfs(i + 1, j - 1, board, visited, cx, cy); // down left
    bool left = dfs(i, j - 1, board, visited, cx, cy); // left
    bool upL = dfs(i - 1, j - 1, board, visited, cx, cy); // up left
    bool up = dfs(i - 1, j, board, visited, cx, cy); // up
    bool upR = dfs(i - 1, j + 1, board, visited, cx, cy); // up right

    return right || downR || down || downL || left || upL || up || upR;
}

void solve(){
    int n;
    cin >> n;

    int ax, ay;
    cin >> ax >> ay;

    
    int bx, by;
    cin >> bx >> by;

    int cx, cy;
    cin >> cx >> cy;

    //0 based 
    ax--, ay--;
    bx--, by--;
    cx--, cy--;

    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<pair<int,int>> dirs = {
        {1,1}, {1,-1},{-1,1},{-1,-1}
    };
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    //fill horizontal
    for(int j = 0; j < n; j++){
        board[ax][j] = 1;
    }

    //fill vertical
    for(int i = 0; i < n; i++){
        board[i][ay] = 1;
    }

    //fill diagonal
    for(auto [dx, dy] : dirs){
        int x = ax + dx;
        int y = ay + dy;

        while(x >= 0 && x < n && y >= 0 && y < n){
            board[x][y] = 1;
            x += dx;
            y += dy;
        }
    }

    if(dfs(bx, by, board, visited, cx, cy)){
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
