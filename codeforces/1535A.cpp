#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        vector<int> a(4);
        for(int i = 0; i < 4; i++){
            cin >> a[i];
        }
        int max1 = max(a[0], a[1]);
        int max2 = max(a[2], a[3]);

        int top[2] = {max1, max2};
        sort(top,top+2,greater<int>());

        int skills[4] = {a[0], a[1], a[2], a[3]};
        sort(skills,skills+4, greater<int>());

        if(top[0] == skills[0] && top[1] == skills[1]){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }

    return 0;
}