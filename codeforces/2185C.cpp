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

        vector<long long> a(n);
        
        for(long long& i : a) cin >> i;

        sort(a.begin(), a.end());

        a.erase(unique(a.begin(), a.end()), a.end());

        int ans = 0;
        int cur = 1;

        for(int i = 1; i < (int)a.size(); i++){
            if(a[i] == a[i-1] + 1){
                cur++;
            }else{
                ans = max(ans, cur);
                cur = 1;
            }
        }
        ans = max(ans, cur);

        cout << ans << "\n";
    }

    return 0;
}