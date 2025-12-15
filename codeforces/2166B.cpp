#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int a, b, n;
        cin >> a >> b >> n;

        if((long long)b*n <= a || b >= a){
            cout << "1\n";
        }else{
            cout << "2\n";
        }
    }


    return 0;
}