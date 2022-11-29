#include <bits/stdc++.h>
using namespace std;

string a, b;

string gao() {
    int n = a.size(), m = b.size();
    while (n > 0 && m > 0) {
        int x = a[n - 1] - '0', y = b[m - 1] - '0';
        if (x + y > 9) return "Hard";
        n--, m--;
    }
    return "Easy";
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    while (cin >> a >> b) cout << gao() << '\n';
    return 0;
}