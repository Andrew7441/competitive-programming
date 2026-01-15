#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;

    vector<int> freq(n + 1);
    for(int x : a) freq[x]++;

    cout << n - (*max_element(freq.begin(), freq.end())) << '\n';
  }
}