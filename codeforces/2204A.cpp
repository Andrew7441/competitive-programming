#include <bits/stdc++.h>
using namespace std;

/**/

void solve(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    int res = 1;

    for(int i = 1; i < (int)s.size(); i++){
        if(s[i] == 'R') res++;
        if(s[i] == 'L'){
            res++;
            break;
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