#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        std::map<int, int> m;

        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            m[x]++;
        }

        vector<int> counts;
        for(auto &p : m) counts.push_back(p.second);

        sort(counts.begin(), counts.end());

        int maxLen = 0;
        for(int k = 1; k <= n; k++){
            int num = 0;
            for(int c : counts){
                if(c >= k) num++;
            }
            maxLen = max(maxLen, num * k);
        }
        cout << maxLen << '\n';
    }

    return 0;
}