#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> p, m, s;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == 1){
            p.push_back(i+1);
        }else if(a[i] == 2){
            m.push_back(i+1);
        }else{
            s.push_back(i+1);
        }
    }

    int w = min({p.size(), m.size(), s.size()});

    cout << w << "\n";

    for(int i = 0; i < w; i++){
        cout << p[i] << " " << m[i] << " " << s[i] << "\n";
    }
    

    return 0;
}