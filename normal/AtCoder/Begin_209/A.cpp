#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x, y;
    while (cin >> x >> y) cout << max(0, y - x + 1) << '\n';
    return 0;
}