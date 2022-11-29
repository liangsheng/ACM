#include <bits/stdc++.h>

using namespace std;

string a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> a >> b) {
        int x = a[0] - '0' + a[1] - '0' + a[2] - '0';
        int y = b[0] - '0' + b[1] - '0' + b[2] - '0';
        cout << max(x, y) << '\n';
    }
    return 0;
}