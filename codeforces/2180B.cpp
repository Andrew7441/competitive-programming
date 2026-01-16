#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<string> a(n);

        for(string& i : a) cin >> i;

        string res = a[0];

        for(int i = 1; i < n; i++){
            if(a[i][0] >= a[i-1][0]){
                res += a[i];
            }else 
                res.insert(0, a[i]);
        }
        cout << res << "\n";
    }

    return 0;
}