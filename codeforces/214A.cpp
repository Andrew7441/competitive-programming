#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int res = 0;
    
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if((i*i) + j == n && i + (j*j) == m){
                res++;
            }
        }
    }

    cout << res;

    return 0;
}