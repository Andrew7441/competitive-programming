#include <bits/stdc++.h>
using namespace std;

/**/

void solve(){
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vector<int> a(q);

    for(int i = 0; i < q; i++){
        cin >> a[i];
        int Query = a[i];
        int res = 0;
        
        while(Query > 0){
            for(char c : s){
                if(Query <= 0) break;
                if(c == 'A' && Query > 0){
                    Query -= 1;
                    res++;
                }else if(c == 'B' && Query > 0){
                    Query /= 2;
                    res++;
                }
            }
            
        }
        cout << res << "\n";
    }
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