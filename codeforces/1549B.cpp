#include <bits/stdc++.h>
using namespace std;

/**/

void solve(){
    int n;
    cin >> n;

    string s,g;
    cin >> s >> g;

    int res = 0;

    for(int i = 0; i < (int)    s.size(); i++){
        if(g[i] == '0') continue;

        if(s[i] == '0'){
            res++;
            s[i] = '2'; //occupied
        }
        else if(i > 0 && s[i-1] == '1'){
            res++;
            s[i - 1] = '2';
        }
        else if(i + 1 < n && s[i + 1] == '1'){
            res++;
            s[i + 1] = '2';
        }
    }
    cout << res << '\n';
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
