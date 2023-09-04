#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (cin >> n) {
        if (n <= 1e3 - 1) cout << n << '\n';
        else if (n <= 1e4 - 1) cout << n / 10 * 10 << '\n';
        else if (n <= 1e5 - 1) cout << n / 100 * 100 << '\n';
        else if (n <= 1e6 - 1) cout << n / 1000 * 1000 << '\n';
        else if (n <= 1e7 - 1) cout << n / 10000 * 10000 << '\n';
        else if (n <= 1e8 - 1) cout << n / 100000 * 100000 << '\n';
        else if (n <= 1e9 - 1) cout << n / 1000000 * 1000000 << '\n';
    }
    return 0;
}