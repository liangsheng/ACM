#include <bits/stdc++.h>
using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int a, b, c;
    while (cin >> a >> b >> c) {
        if (a == b) cout << c << '\n';
        else if (a == c) cout << b << '\n';
        else if (b == c) cout << a << '\n';
        else cout << "0\n";
    }
    return 0;
}