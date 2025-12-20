#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;

        vector<string> a(n);

        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        int res = 0;

        for(size_t i = 0; i < a.size(); i++){
            if(a[i].size() <= m){
                res++;
                m -= a[i].size();
            }else{
                break;
            }
        }
        cout << res << '\n';
    }

    return 0;
}