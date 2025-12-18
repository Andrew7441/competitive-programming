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
        set<int> s;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            s.insert(a[i]);
        }

        int d = s.size();
        int ans = INT_MAX;
        for(int x : a){
            if(x >= d){
                ans = std::min(ans, x);
            }
        }
        
        std::cout << ans << '\n';
    }

    return 0;
}