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

        char ch;
        vector<int> res;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= 4; j++){
                cin >> ch;
                if(ch == '#'){
                    res.push_back(j);
                }
            }
        }

        reverse(res.begin(), res.end());
        for(int i : res){
            cout << i << " ";
        }
        cout << "\n";

    }

    return 0;
}