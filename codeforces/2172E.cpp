#include <bits/stdc++.h>
using namespace std;

/**/

void permute(string& s, int index, vector<string>& permutations){
    if(index == (int)s.size()){
        permutations.push_back(s);
        return;
    }

    for(size_t i = index; i < s.size(); i++){
        swap(s[index], s[i]);
        permute(s, index + 1, permutations);
        swap(s[index], s[i]);
    }
}

void solve(){
    string n;
    int j, k;

    cin >> n >> j >> k;

    vector<string> permutations;
    permute(n, 0, permutations);
    sort(permutations.begin(), permutations.end());

    string s1 = permutations[j-1];
    string s2 = permutations[k-1];

    int a = 0, b = 0;

    for(size_t i = 0; i < s1.size(); i++){
        for(size_t j = 0; j < s2.size(); j++){
            if(s1[i] == s2[j]){
                if(i == j) a++;
                else b++;
            }
        }
    }

    cout << a << "A" << b << "B\n"; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}
