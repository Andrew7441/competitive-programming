#include <bits/stdc++.h>
using namespace std;

/**/

void solve(){
    int n;
    cin >> n;

    vector<int> a(n);

    for(int& i : a) cin >> i;

    int res; 

    for(int i = 0; i < (int)a.size(); i++){
        int k = INT_MIN;
        res = 0;
        for(int j = 0; j < (int)a.size(); j++){
            
            if(i < j){
                while(k != INT_MAX){
                    if(abs(a[i] - k) > abs(a[j] - k)){
                        res++;
                    }
                    k++;
                }
            }
            cout << res << " ";    
        }
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}