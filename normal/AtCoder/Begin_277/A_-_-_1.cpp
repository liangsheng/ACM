#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x, y;
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> y;
        if (y == x) cout << i << '\n';
    }
    return 0;
}