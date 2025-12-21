#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        int cheapest = INT_MAX;
  
        vector<int> ind;

        for(int i = 0; i < n; i++){
            if(a[i] < cheapest){
                cheapest = a[i];
            }else{
                ind.push_back(i+1);
            }
        }
        int size = ind.size();

        cout << size << '\n';
        for(int i : ind){
            cout << i << " ";
        }
        cout << "\n";
    }

    return 0;
}