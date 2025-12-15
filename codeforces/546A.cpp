#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, n, w;
    cin >> k >> n >> w;

    int total = 0;

    for(int i = 1; i <= w; i++){
        total += i * k;
    }

    int need = total - n;

    if(total < n){
        cout << 0;
    }else{
        cout << need << '\n';
    }

    return 0;
}