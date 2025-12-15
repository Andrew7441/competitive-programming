#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    int available = 240 - k;
    int total =  0;
    int res = 0;

    for(int i = 1; i <= n; i++){
        total += i * 5;
        if(total > available) break;
        res++;
    }

    cout << res << "\n";
    
    return 0;
}

