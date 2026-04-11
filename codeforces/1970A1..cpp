#include <bits/stdc++.h>
using namespace std;

/**/

string solve(){
    string s;
    cin >> s;

    vector<tuple<int,int,char>> prefBal;
    int pref = 0;

    for(int i = 0; i < (int)s.length(); i++){
        prefBal.push_back({pref, i, s[i]});
        if(s[i] == '(') pref++;
        else pref--;
    }

    sort(prefBal.begin(), prefBal.end(), [](const auto& a, 
    const auto& b){
        if(get<0>(a) == get<0>(b)) return get<1>(a) > get<1>(b);
        else return get<0>(a) < get<0>(b);
    });

    string res = "";

    for(auto& p: prefBal){
        res += get<2>(p);
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << solve();

    return 0;
}