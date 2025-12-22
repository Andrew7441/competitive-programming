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

        string a;
        cin >> a;
        
        int m;
        cin >> m;

        string b;
        cin >> b;

        string c;
        cin >> c;

        list<char> res;
        for(char i : a){
            res.push_back(i);
        }

        for(int i = 0; i < m; i++){
            if(c[i] == 'D'){
                res.push_back(b[i]);
            }else{
                res.push_front(b[i]);
            }
        }

        std::string z(res.begin(), res.end());

        cout << z << "\n";

    }

    return 0;
}