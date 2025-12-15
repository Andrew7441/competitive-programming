#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/1325/B CopyCopyCopyCopyCopy
/*
Greedy approach
Objective
    determine the length of the longest strictly increasing subsequence (LIS) 
    of the array formed by concatenating the original array n times.
Constraint
    LIS is strictly increasing, duplicates cannot contribute to making it longer.
    take all distinct elements in sorted order.
    The length of the LIS = number of distinct elements.
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while(t--){
        int n;
        cin >> n;
        set<int> st;

        while(n--){
            int a;
            cin >> a;
            st.insert(a); 
        }
        cout << st.size() << "\n";

    }
    return 0;
}