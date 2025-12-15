#include <iostream>
using namespace std;

//https://codeforces.com/problemset/problem/427/A Police Recruits

int main() {

    int n;
    cin >> n;
    
    int officers = 0; 
    int untreated = 0;

    for(int i = 0; i < n; i++){
        int x; 
        cin >> x;

        if(x>0) officers+=x;
        else if(officers>0) officers--;
        else untreated++;
    }

    cout << untreated;

    return 0;
}