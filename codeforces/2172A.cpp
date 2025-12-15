#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/2172/A ASCII Art Contest

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int g, c, l;
    cin >> g >> c >> l;

    int min = std::min({g, c, l});
    int max = std::max({g, c, l});

    if(max - min >= 10){
        cout << "check again"; 
    }else{
        int median = g + c + l - min - max; 
        cout << "final " << median;
    }

    
    
    return 0;
}