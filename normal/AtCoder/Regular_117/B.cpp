#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n;
int a[N];

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    while (cin >> n) {
        for (int i = 1; i <= n; i++) cin >> a[i];
    }
    return 0;
}

// 2 1
// 3 1
// 4 1
// 5 1 2 3
// 6 1
// 7 1 2 3 4 5
// 8 1 3 5 7
// 9 1 2 3 4 5 6 7
// 10 1 3 7