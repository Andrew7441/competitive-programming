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