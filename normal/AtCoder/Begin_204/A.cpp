#include <bits/stdc++.h>
using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int x, y;
    while (cin >> x >> y) {
        if (x == y) cout << x << '\n';
        else if (x != 0 && y != 0) cout << "0\n";
        else if (x != 1 && y != 1) cout << "1\n";
        else cout << "2\n";
    }
    return 0;
}