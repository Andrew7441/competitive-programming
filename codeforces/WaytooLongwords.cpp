#include <bits/stdc++.h>
#include<iostream>
#include<string>


using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n; 

    while(n--){
        string word; 
        cin >> word;

        if(word.length() > 10){
            cout << word.front() << word.length() - 2 << word.back() << endl;
        }else{
            cout << word << endl;
        }
    }
    return 0;
}


