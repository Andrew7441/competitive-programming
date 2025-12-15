#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        cout << n - 1 << "\n";
    }

    return 0;
}







// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin >> t;

//     while(t--){
//         int a;
//         cin >> a;

//         int res = 0;

//         for(int i = 0; i < a; i++){
//             for(int j = 0; j < a; j++){
//                 if(i == a - j){
//                     res++;
//                 }
//             }
//         }

//         cout << res << "\n";
//     }

//     return 0;
// }