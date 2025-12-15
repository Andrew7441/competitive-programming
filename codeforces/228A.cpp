#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int res = 0;
    unordered_set<int> s;

    for(int i = 0; i < 4; i++){
        int a;
        cin >> a;
        if(s.count(a)) res++;
        s.insert(a);
    }

    cout << res;

    return 0;
}