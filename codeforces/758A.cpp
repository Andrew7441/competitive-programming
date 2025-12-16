#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long long max_a = 0, sum = 0;

    for(int i = 0; i < n; i++){
        long long x;
        cin >> x;

        if(x > max_a) max_a = x;
        sum += x;
    }

    cout << (max_a * n - sum) << endl;



    return 0;
}