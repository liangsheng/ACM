#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a, b;
    while (cin >> a >> b) {
        string x = a + b, y = b + a;
        if (x < y) cout << "<" << '\n';
        else if (x == y) cout << "=" << '\n';
        else cout << ">" << '\n';
    }
    return 0;
}