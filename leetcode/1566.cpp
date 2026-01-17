#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int c = 0;

        for(int i = 0; i + m < (int)arr.size(); i++){
            if(arr[i] != arr[i+m])
                c = 0;

            c += (arr[i] == arr[i+m]);   

            if(c == (k-1)*m) return true;
        }

        return false;
    }
};

int main() {
    cout << boolalpha;
    vector<int> arr{1,2,4,4,4,4};
    int m = 1, k = 3;

    Solution S;

    cout << S.containsPattern(arr, m, k);
}