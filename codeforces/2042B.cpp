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

        vector<int> c(n);
        for(int i = 0; i < n; i++) cin >> c[i];
        
        vector<int> freq(n+1, 0);

        for(int x : c) freq[x]++;

        int single = 0, multi = 0;

        for(int i = 1; i <= n; i++){
            if(freq[i] == 1) single++;
            else if(freq[i] > 1) multi++;
        }


        int alice = multi + ((single + 1) / 2) * 2;

        cout << alice << '\n';
    }

    return 0;
}