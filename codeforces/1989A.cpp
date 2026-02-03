#include <bits/stdc++.h>
using namespace std;

void solve(){

    int x, y;
    cin >> x >> y;

    if(y < -1){
        cout << "NO\n";
    }else{
        cout << "YES\n";
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while(n--){
        solve();
    }   

    return 0;
}