#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/1760/A Medium Number

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    vector<int> x(3);

    while(t--){
        for(size_t i = 0; i < x.size();i++){
            cin >> x[i];
        }

        sort(x.begin(), x.end());

        cout << x[1] << endl;

    }

    return 0;
}