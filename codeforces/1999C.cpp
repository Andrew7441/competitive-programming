#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n, s, m;
        cin >> n >> s >> m;

        vector<pair<long long, long long>> segs(n);

        for(int i = 0; i < n; i++){
            cin >> segs[i].first >> segs[i].second;
        }
        bool ok = false;

        if(segs[0].first >= s){
            ok = true;
        }

        for(int i = 1; i < n; i++){
            if(segs[i].first - segs[i-1].second >= s){
                ok = true;
            }
        }

        if(m - segs[n-1].second >= s){
            ok = true;
        }

        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }


    return 0;
}