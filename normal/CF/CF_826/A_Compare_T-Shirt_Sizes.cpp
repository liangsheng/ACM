#include <bits/stdc++.h>
using namespace std;

string gao(string a, string b) {
    if (a == b) return "=";
    int n = a.size(), m = b.size();
    if (a[n - 1] != b[m - 1]) {
        if (a[n - 1] == 'S') return "<";
        if (a[n - 1] == 'L') return ">";
        if (b[m - 1] == 'S') return ">";
        if (b[m - 1] == 'L') return "<";
    }
    if (a[n - 1] == 'L') {
        if (n > m) return ">";
        return "<";
    }
    if (n > m) return "<";
    return ">";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        string a, b;
        cin >> a >> b;
        cout << gao(a, b) << '\n';
    }
    return 0;
}