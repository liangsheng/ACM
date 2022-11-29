#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x = 50;
    for (int i = 2; i * i <= x; i++) {
        if (x % i) continue;
        cout << i << '\n';
        while (x % i == 0) x /= i;
    }
    if (x != 1) cout << x << '\n';
    int T, n, m;
    cin >> T;

    return 0;
}