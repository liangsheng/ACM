#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, x, y;
    cin >> T;
    while (T--) {
        cin >> x >> y;
        if (x < y) cout << "FIRST" << '\n';
        else if (x == y) cout << "ANY" << '\n';
        else cout << "SECOND" << '\n';
    }
    return 0;
}