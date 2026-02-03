#include <bits/stdc++.h>
using namespace std;

int bad;  

bool isBadVersion(int version) {
    return version >= bad;
}

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, h = n;
        while (l < h) {
            int mid = l + (h - l) / 2; 
            if (isBadVersion(mid))
                h = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};

int main() {
    int n = 5;
    bad = 4; 

    Solution sol;
    cout << "First bad version: " << sol.firstBadVersion(n) << endl;

    return 0;
}
