#include <iostream>
using namespace std;

//https://codeforces.com/problemset/problem/785/A  Anton and Polyhedrons

int main() {

    int n;
    cin >> n;

    int res = 0;

    for(int i = 0; i < n; i++){
        string s; cin >> s;
        if(s == "Icosahedron"){
            res += 20;
        }else if(s == "Dodecahedron"){
            res += 12;
        }else if(s == "Octahedron"){
            res += 8;
        }else if(s == "Cube"){
            res += 6;
        }else{
            res += 4;
        }
    }
    cout << res;

    return 0;
}