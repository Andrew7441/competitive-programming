#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int res = 0;
    int i = 0;
    while(i < n){
        if(s[i] == 'B'){
            res++;
            i+=k;
        }else{
            i++;
        }
    }

    cout << res << "\n";
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