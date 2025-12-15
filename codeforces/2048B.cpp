#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> p(n + 1, 0);
        int cur = 1;

        // Place 1,2,3,... at positions k,2k,3k,...
        for (int i = k; i <= n; i += k) {
            p[i] = cur++;
        }

        // Fill remaining positions with the remaining numbers
        for (int i = 1; i <= n; i++) {
            if (p[i] == 0) {
                p[i] = cur++;
            }
        }

        for (int i = 1; i <= n; i++) {
            cout << p[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
