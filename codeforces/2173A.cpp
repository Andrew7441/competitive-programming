#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int x = 0;
    int res = 0;

    for(int i = 0; i < s.length(); i++){
        if(s[i] == '1')
            x = k;
        else if(s[i] == '0' && x > 0){
            x--;
        }else if(s[i] == '0' && x <= 0){
            res++;
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