#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/268/A Games

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int res = 0;
    int n;
    cin >> n;
    vector<int> home(n);
    vector<int> guest(n);

    for(int i = 0; i < n; i++){
        cin >> home[i] >> guest[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) continue;

            if(home[i] == guest[j]) res++;
        }
    }

    cout << res << "\n";


    return 0;
}