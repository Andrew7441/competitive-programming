#include <bits/stdc++.h>
using namespace std;

int simulate(int a, int b, bool whiteStart){
    int sz = 1;
    int layers = 0;
    bool whiteTurn = whiteStart;

    while(true){
        if(whiteTurn){
            if(a < sz) break;
            a -= sz;            
        }else{
            if(b < sz) break;
            b -= sz;
        }

        sz *= 2;
        layers++;
        whiteTurn = !whiteTurn;
    }

    return layers;
}

void solve(){
    int a, b;
    cin >> a >> b;

    cout << max(simulate(a, b, true), simulate(a,b, false)) << "\n";
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