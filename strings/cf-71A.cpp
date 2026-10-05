// Codeforces 71A — Way Too Long Words
// https://codeforces.com/problemset/problem/71/A
// Topic: strings | Tags: implementation
// Complexity (yours): O(total length) time, O(max word length) space
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



/*
💭 First Idea: If a word is longer than 10, print its first letter, length - 2, and last letter.
🧩 Key Property / Invariant: The abbreviation depends only on the first char, last char and the length.
✅ Key insight: word.front() + (len - 2) + word.back() for len > 10, else the word itself.
🔁 Recognition cue for next time: "Abbreviate long words" -> string front/back/size.
⏱  Speed fix for next time: Use "\n" instead of endl to avoid flushing on every line.
🛠  Review: correct; O(total length) -> Already optimal.
*/
