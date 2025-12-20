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

        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            mp[x]++;
        }

        int res = 0;

        for(auto &[x, cnt] : mp){
            if(cnt >= x){
                res += cnt - x;
            }else{
                res += cnt; 
            }
        }

        cout << res << "\n";

    }

    return 0;
}