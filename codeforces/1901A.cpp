#include <bits/stdc++.h>
using namespace std;
//https://codeforces.com/problemset/problem/1901/A Line Trip

//greedy approach
//Objective:
//For each test case, print one integer — the minimum possible 
//volume of the gas tank in your car that will allow you to travel from the point 0
//to the point x and back.
//Constraint:number of test cases, number of stations, distance limits, station positions

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

     int t;
     cin >> t;

     while(t--){
        int n, x;
        cin >> n >> x;

        vector<int> point(n);
        for(int i = 0; i < n; i++){
            cin >> point[i];
        }

        int res = 0;
        res = max(res, point[0]);

        for(int i = 1; i < n; i++){
            res = max(res, point[i] - point[i-1]);
        }

        res = max(res, 2 * (x - point[n-1]));

        cout << res << "\n";

     }

    return 0;
}