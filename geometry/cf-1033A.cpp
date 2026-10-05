// Codeforces 1033A — King Escape
// https://codeforces.com/problemset/problem/1033/A
// Topic: geometry | Tags: graphs, math
// Complexity (yours): O(n^2) time, O(n^2) space (recursion depth up to ~n^2)
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

// ===================== ⚡ Optimized =====================
// O(1) instead of O(n^2) DFS (and no deep recursion): the queen's row/column split the board into 4 quadrants
// that the king can never cross, and each quadrant is king-connected -> just check B and C are in the same quadrant.
// To submit: replace your solve() with this one.
namespace optimized {
void solve() {
    int n, ax, ay, bx, by, cx, cy;
    cin >> n >> ax >> ay >> bx >> by >> cx >> cy;
    bool sameRowSide = (bx < ax) == (cx < ax);
    bool sameColSide = (by < ay) == (cy < ay);
    cout << (sameRowSide && sameColSide ? "YES" : "NO") << '\n';
}
}

/*
💭 First Idea: Mark queen-attacked cells and DFS the king from B to C over safe cells.
🧩 Key Property / Invariant: The queen's row and column are walls the king can never cross; diagonals don't separate the quadrants further.
✅ Key insight: Answer is YES iff B and C lie in the same quadrant relative to the queen: (bx<ax)==(cx<ax) && (by<ay)==(cy<ay).
🔁 Recognition cue for next time: Grid reachability with an infinite-range blocker → think about which regions the lines cut the board into.
⏱  Speed fix for next time: Recursive DFS on 10^6 cells risks stack overflow; use BFS/iterative DFS, or skip search entirely.
🛠  Review: correct (stack-heavy); yours O(n^2) → optimized O(1).
*/
