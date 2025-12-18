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

        vector<int> cnt(n+1, 0);
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            cnt[x]++;
        }

        int res = 0;

        for(int i = 1; i <= n; i++){
            res += cnt[i] / 2;
        }

        cout << res << "\n";


    }

    return 0;
}


//above is O(n)
//my solution:O(n^2)
/*
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        int res = 0;
        int chosen[n]{0};

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(a[i] == a[j] && i < j && chosen[i] == 0 && chosen[j] == 0){
                    res++;
                    chosen[i]++;
                    chosen[j]++;
                }
            }
        }
        cout << res << "\n";
    }

    return 0;
}
*/