#include <bits/stdc++.h>
using namespace std;

/**/

void solve(){
    int a, b;
    cin >> a >> b;

    int xK, yK;
    cin >> xK >> yK;

    int xQ, yQ;
    cin >> xQ >> yQ;

   vector<pair<int,int>> moves {
    {a, b}, {a,-b}, {-a, b}, {-a, -b},
    {b, a}, {b, -a}, {-b, a}, {-b,-a}
   };

   set<pair<int,int>> KingPos;
   set<pair<int,int>> QueenPos;

   for(auto [dx, dy] : moves){
    KingPos.insert({xK + dx, yK + dy});
    QueenPos.insert({xQ + dx, yQ + dy});
   }

   int ans = 0;
   for(auto& p: KingPos){
    if(QueenPos.count(p)) ans++;
   }

   cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}