#include <bits/stdc++.h>
using namespace std;

void solve(){
    int l, r;
    cin >> l >> r;

    int largestdiff = -1;
    int largestnum = l;

    for(int i = l; i <= min(r, l + 100); i++){
        int largest = INT_MIN, smallest = INT_MAX;
        string s = to_string(i);
        for(char& c: s){
            int d = c - '0';
            largest = max(largest, d);
            smallest = min(smallest, d);
        }

        int diff = largest - smallest;
        
        if(diff > largestdiff){
            largestdiff = diff;
            largestnum = i;
        }
    }

    cout << largestnum << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        solve();

    }

    return 0;
}