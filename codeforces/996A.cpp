#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    int count = 0;
    int bills[] = {100, 20, 10, 5, 1};

    for(int b: bills){
        count += n / b;
        n %= b;
    }

    cout << count << '\n';



    return 0;
}