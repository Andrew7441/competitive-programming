#include <iostream>
#include<string>

using namespace std;

//https://codeforces.com/problemset/problem/1703/A

int main() {

    int n; cin >> n;

    for(int i = 0; i < n; i++){
        string s; 
        cin >> s;
        for(char &i : s){
            i = tolower(i);
        }
        if(s == "yes"){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}