#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    int a=0, b = 0, c = 0, d = 0;
    for(char i : s){
        if(i == 'A'){
            a++;
        }else if(i == 'B'){
            b++;
        }else if(i == 'C'){
            c++;
        }else if(i == 'D'){
            d++;
        }
    }

    cout << min(a, n) + min(b, n) + min(c, n) + min(d, n);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}