#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/problemset/problem/1560/A Dislike of Threes

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
	cin >> t;

	while (t--)
	{
		int k;
		cin >> k;

		for (int i = 1; ; i++)
		{
			if (i % 3 == 0 || i % 10 == 3)
				continue;
			if (--k == 0)
			{
				cout << i << '\n';
				break;
			}
		}
	}

    return 0;
}

/*
Test Case 1: k = 1

Liked numbers encountered:

i=1  k: 1→0  OUTPUT=1

Test Case 2: k = 2

Liked numbers encountered:

i=1  k: 2→1
i=2  k: 1→0  OUTPUT=2

Test Case 3: k = 3

Liked numbers:

i=1  k: 3→2
i=2  k: 2→1
i=4  k: 1→0  OUTPUT=4

Test Case 4: k = 4

Liked numbers:

i=1  k: 4→3
i=2  k: 3→2
i=4  k: 2→1
i=5  k: 1→0  OUTPUT=5

Test Case 5: k = 5

Liked:

i=1  k: 5→4
i=2  k: 4→3
i=4  k: 3→2
i=5  k: 2→1
i=7  k: 1→0  OUTPUT=7

Test Case 6: k = 6

Liked:

i=1  k: 6→5
i=2  k: 5→4
i=4  k: 4→3
i=5  k: 3→2
i=7  k: 2→1
i=8  k: 1→0  OUTPUT=8

Test Case 7: k = 7

Liked:

i=1  k: 7→6
i=2  k: 6→5
i=4  k: 5→4
i=5  k: 4→3
i=7  k: 3→2
i=8  k: 2→1
i=10 k: 1→0  OUTPUT=10

Test Case 8: k = 8

Liked:

i=1  k: 8→7
i=2  k: 7→6
i=4  k: 6→5
i=5  k: 5→4
i=7  k: 4→3
i=8  k: 3→2
i=10 k: 2→1
i=11 k: 1→0  OUTPUT=11

Test Case 9: k = 9

Liked:

i=1  k: 9→8
i=2  k: 8→7
i=4  k: 7→6
i=5  k: 6→5
i=7  k: 5→4
i=8  k: 4→3
i=10 k: 3→2
i=11 k: 2→1
i=14 k: 1→0  OUTPUT=14


*/