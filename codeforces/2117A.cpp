#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n, x;
        cin >> n >> x;

        int l = 1e5, r = -1; 
        for(int i = 0; i < n; i++){
            int door;
            cin >> door;
            
            
            if(door == 1){
                l = min(l, i);
                r = max(r, i);
            }
        }

        cout << (x >= r - l + 1 ? "YES\n" : "NO\n");
    }


    return 0;
}