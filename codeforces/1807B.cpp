#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/1807/B Grab the Candies

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        reverse(a.begin(),a.end());

        int m = 0;
        int b = 0;

        for(int i : a){
            if(i % 2 == 0){
                m += i;
            }else{
                b += i;
            }
        }

        if(m > b){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }

    return 0;
}