#include <bits/stdc++.h>
using namespace std;


int main() {

    int n; 
    cin >> n;

    int p;
    cin >> p;

    unordered_set<int> st1; 

    for(int i = 0; i < p; i++){
        int x; 
        cin >> x;
        st1.insert(x);
    }

    int q; 
    cin >> q;

    for(int i = 0; i < q; i++){
        int y;
        cin >> y; 
        st1.insert(y);
    }

    if(st1.size() == (size_t)n){
        cout << "I become the guy.\n";
    }else{
        cout << "Oh, my keyboard!\n";
    }

    return 0;
}