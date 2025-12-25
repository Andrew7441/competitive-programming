#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        vector<int> a(n+1);
        for(int i = 1; i <= n; i++) cin >> a[i];

        int rb = 0;
        int res = 0;

        for(int i = 1; i <= n; i++){
            if(a[i] >= k){
                rb += a[i];
            }
            if(a[i] == 0 && rb > 0){
                rb--;
                res++;
            }
        }

        cout << res << "\n";

    }

    return 0;
}