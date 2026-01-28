#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin >> s;

    char col = s[0];
    char row = s[1];
    
    for(int i = 1; i <= 8; i++){
        if(i != (row - '0')){
            cout << col << i << "\n";
        }
    }
    for(char l = 'a'; l <= 'h'; l++){
        if(l != col){
            cout << l << row << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}