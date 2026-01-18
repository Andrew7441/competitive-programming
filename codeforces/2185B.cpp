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

        vector<int> a(n);
        for(int& i : a) cin >> i;

        int maximum = *max_element(a.begin(), a.end());

        int res = 0;
        for(int i = 0; i < n; i++){
            res += maximum;
        }
        cout << res << "\n";
    }

    return 0;
}