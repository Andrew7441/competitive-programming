#include <bits/stdc++.h>
using namespace std;


void solve(){
    int a, b;
    cin >> a >> b;

    vector<int> res;
    res.push_back(b);
    
    while(b > a){
        if(b % 10 == 1){
            b /= 10;
        }
        else if(b % 2 == 0){
            b /= 2;
        }
        else {
            break;
        }
        res.push_back(b);
    }

    if(b != a){
        cout << "NO\n";
        return;
    }

    reverse(res.begin(), res.end());

    cout << "YES\n" << res.size() << "\n";
    for(int& i : res){
        cout << i << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
