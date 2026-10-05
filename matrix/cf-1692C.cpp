// Codeforces 1692C — Where's the Bishop?
// https://codeforces.com/problemset/problem/1692/C
// Topic: matrix | Tags: implementation
// Complexity (yours): O(64) per test, O(1) space
#include <iostream>
#include<string>
using namespace std;

//https://codeforces.com/problemset/problem/1692/C Where's the Bishop?


void solve(){
    char g[9][9];

    for(int r = 1; r <= 8; r++){
        for(int c = 1; c <= 8; c++){
            cin >> g[r][c];
        }
    }

    for(int i = 2; i <= 7; i++){
        for(int j = 2; j <= 7; j++){
            if(g[i][j] == '#' && g[i-1][j-1] == '#' && g[i-1][j+1] == '#' 
                && g[i+1][j-1] == '#' && g[i+1][j+1] == '#'){
                    cout << i << ' ' << j << '\n';
                    return; 
                }
        }
    }

}

int main() {

    int t; 
    cin >> t; 
    while(t--){
        solve();
    }
  
    return 0;
}

/*
💭 First Idea: Scan inner cells, find the one whose 4 diagonal neighbours are all '#'.
🧩 Key Property / Invariant: The bishop is never on the border (2 <= r,c <= 7), and it's the only cell with an X shape around it.
✅ Key insight: Pattern match a fixed 3x3 'X' in the grid.
🔁 Recognition cue for next time: 'Find the centre of a shape in a small grid' -> check neighbours of each inner cell.
⏱  Speed fix for next time: 1-indexed grid makes the answer print directly with no +1.
🛠  Review: correct; Already optimal.
*/
