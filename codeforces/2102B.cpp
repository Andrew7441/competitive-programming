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

        for(int i = 0; i < n; i++) a[i] = abs(a[i]);

        vector<int> b = a;
        sort(b.begin(), b.end());

        int mid = (n+1) / 2 - 1;
        if(a[0] <= b[mid]){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }

    return 0;
}