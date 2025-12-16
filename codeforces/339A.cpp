#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    vector<int> res;
    string r = "";

    for(size_t i = 0; i < s.length(); i++){
        if(isdigit(s[i])){
            res.push_back(s[i]);
        }
    }

    sort(res.begin(), res.end());

    for(int i:res){
        r += i;
        r += "+";
    }

    r.pop_back();

    cout << r << '\n';

    return 0;
}