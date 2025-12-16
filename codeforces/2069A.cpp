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

        vector<int> b(n-2);
 

        for(int i = 0; i < n - 2; i++){
            cin >> b[i];
        }

        bool valid = true;

        for(int i = 1; i < n - 3; i++){
            if(b[i - 1] == 1 && b[i] == 0 && b[i + 1] == 1){
                valid = false;
            }
        }

        if(valid){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }

        
    }

    return 0;
}