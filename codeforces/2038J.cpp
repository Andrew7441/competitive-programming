#include <bits/stdc++.h>
using namespace std;

/**/

int people = 0, bus = 0;

void solve(){
    char e;
    cin >> e;
    int x;
    cin >> x;

    if(e == 'P') people += x;
    else{
        bus += x;
        if(bus - people > 0){
            cout << "YES\n";
            people = 0;
            bus = 0;
        }else{
            cout << "NO\n";
            people -= bus;
            bus = 0;
        }
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