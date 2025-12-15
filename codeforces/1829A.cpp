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
        
        int res = 0;
        int var = 0;
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            if(a == 0){
                res++;
                var = max(res, var);
            }else{
                res = 0;
            }
        }

        cout << var << endl;
    }

    return 0;
}