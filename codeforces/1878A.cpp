#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/1878/A How Much Does Daytona Cost?

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;

    while(t--){
        int n,k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        int countk = 0;
        for(int x : a){
            if(x == k){
                countk++;
            }
        }

        if(countk == 0){
            cout << "NO\n";
        }else{
            cout << "YES\n";
        }

    }


    return 0;
}