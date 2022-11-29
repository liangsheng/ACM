#include <bits/stdc++.h>
using namespace std;

int T, n, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> n >> k;
        for (int i = 1; i <= 2 * k - n - 1; i++) cout << i << ' ';
        for (int i = k; i >= 2 * k - n; i--) cout << i << ' ';
        puts("");
    }
    return 0;
}