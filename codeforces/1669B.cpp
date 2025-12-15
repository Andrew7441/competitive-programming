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

        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        unordered_map<int, int>freq;
        bool found = false; 

        for(int i = 0; i < n; i++){
            freq[a[i]]++;
        }

        for(auto &p : freq){
            if(p.second >= 3){
                cout << p.first << "\n";
                found = true; 
                break;
            }
        }
        if(!found) cout << -1 << "\n";
    }

    return 0;
}

