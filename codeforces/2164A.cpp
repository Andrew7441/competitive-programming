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
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());


        int x;
        cin >> x;

        long long mn = *min_element(a.begin(), a.end());
        long long mx = *max_element(a.begin(), a.end());

        if(n == 1){
            cout << (a[0] == x ? "YES\n" : "NO\n");
        }else{
            cout << ((mn <= x && mx >= x) ? "YES\n" : "NO\n");
        }

    }

    return 0;
}

