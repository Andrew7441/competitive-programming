#include <iostream>
#include<vector>
using namespace std;

//https://codeforces.com/problemset/problem/158/A 


int main() {

    int n , k;
    cin >> n >> k;

    vector<int> pos(n); 

    for(int i = 0; i < n; i++){
        cin >> pos[i];
    }

    int threshold = pos[k - 1];
    int res = 0; 

    for(int score : pos){
        if(score >= threshold && score > 0){
            res++;
        }
    }
    
    cout << res;

    return 0;
}