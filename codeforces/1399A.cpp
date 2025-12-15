#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/1399/A Remove Smallest
// greedy, sortings
// objective : reduce array to one element
// constraint: i may remove one element if i pick 2 indices i != j  such that ∣ai​−aj​∣≤1
// i must remove the smaller of the two (or either one if equal)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t; 

    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int& x : a) cin >> x;

        sort(a.begin(),a.end());

        bool ok = true;
        for(int i = 1; i < n; i++){
            if(abs(a[i-1] - a[i]) > 1){
                ok = false; 
                break;
            }
        }
        
        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}