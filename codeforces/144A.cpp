#include <iostream>
#include<vector>
using namespace std;

//https://codeforces.com/problemset/problem/144/A  Arrival of the General

int main() {

    int n; 
    cin >> n; 

    vector<int> a(n);


    for(int i = 0; i < n; i++) cin >> a[i];   
    
    int min_h = a[0];
    int max_h = a[0];
    int max_i = 0, min_i = 0;

    for(int i = 0; i < n; i++){
        if(max_h < a[i]){
            max_h = a[i];
            max_i = i;
        }

        if(min_h >= a[i]){
            min_h = a[i];
            min_i = i;
        }
    }

    int moves = max_i + (n - 1 - min_i);
    
    if(max_i > min_i) moves--;

    cout << moves; 


    return 0;
}

/*
Understand the goal condition
The general only checks two things:
The first soldier must be the tallest.
The last soldier must be the shortest.
Everything else is irrelevant.
→ So we only care about moving one max and one min soldier.

Measure how far they are from their target positions

The first tallest soldier must move from its index max_i to the front (0), costing max_i swaps (each swap moves it one left).

The last shortest soldier must move from its index min_i to the back (n-1), costing (n−1−min_i) swaps (each swap moves it one right).

Adjust for dependency between moves
If the max is to the right of the min (max_i > min_i), then when the max moves left first, it shifts the min one step right automatically — saving one swap.
That’s why we subtract 1 in that case.

No simulation needed
Because swapping adjacent elements is symmetric and each move changes index by exactly 1, you can directly count positions rather than simulate — that’s the key optimization insight.

So the intuition is:
→ Model the problem as index movement, not as a sequence of swaps.
*/