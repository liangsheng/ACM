#include <bits/stdc++.h>
using namespace std;

const int N = 10005;

int T, n, x, d;
int a[N];

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= n; i++) {
            cin >> x;
            d = max(1, (x - 1) / 2);
        }
    }
    return 0;
}