#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int x, y;
        cin >> x >> y;

        if(x > y){
            int temp = x;
            x = y;
            y = temp;
        }
        cout << x << " " << y << "\n";
    }

    return 0;
}