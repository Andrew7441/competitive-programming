#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/**/

void solve(){
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> weight(10, 0);
    vector<int> cantZero(10, false);

    for(int k = 0; k < n; k++){
        string s;
        cin >> s;
        
        // no leading zero
        cantZero[s[0] - 'a'] = true;

        long long place = 1;
        for(int i = (int)s.size() - 1; i >= 0; i--){
            int id = s[i] - 'a';
            weight[id] += place;
            place *= 10;
        }
    }

    long long best = __LONG_LONG_MAX__;

    for(int zero = 0; zero < 10; zero++){
        if(cantZero[zero]) continue;

        vector<int> letters;
        for(int i = 0; i < 10; i++){
            if(i != zero) letters.push_back(i);
        }

        sort(letters.begin(), letters.end(), [&](int a, int b){
            return weight[a] > weight[b];
        });

        long long sum = 0;
        int digit = 1;

        for(int id : letters){
            sum += weight[id] * digit;
            digit++;
        }

        best = min(best, sum);
    }

    cout << best << '\n';


    return 0;
}
