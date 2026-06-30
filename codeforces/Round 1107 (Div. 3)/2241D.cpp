#include <bits/stdc++.h>
using namespace std;

/*
couldnt solve it gng :/
kol el e7tram to those who done it without ai
*/

void solve(){
    int n;
    cin >> n;

    vector<int> a(n), b(n);

    for(int& i : a){
        cin >> i;
    }
    
    for(int& i : b){
        cin >> i;
    }

    if(a == b){
        cout << "YES\n";
        return;
    }

    int l = 0, r = n - 1;

    while(l < r){
        vector<int> x = a;
        vector<int> y = b;

        for(int i = l; i <= r; i++){
            if(x[i] != y[i] && (i - l) % 2 == 0){
                x[i]++;
                if(x[i] == b[i]) a = x;
            }else if(x[i] != y[i] && (i - l) % 2 != 0){
                x[i]--;
                if(x[i] == b[i]) a = x;
            }

            if(x == y){
                cout << "YES\n";
                return;
            }
        }
        l++;
    }

    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}

/*
💭 First Idea
🧩 Key Property / Invariant
✅ Key insight
🔁 Recognition cue for next time
⏱  Speed fix for next time
*/