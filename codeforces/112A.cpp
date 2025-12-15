#include <iostream>
#include <cctype>
using namespace std;

int main() {



    std::string s1, s2;
    cin >> s1 >> s2; 


    for(auto &i : s1){
        i = tolower(static_cast<unsigned char>(i));
    }
    for(auto &i : s2){
        i = tolower(static_cast<unsigned char>(i));
    }

    
    if(s1 == s2){
        cout << 0; 
    }else if(s1 < s2){
        cout << -1;
    }else{
        cout << 1; 
    }

    return 0;
}