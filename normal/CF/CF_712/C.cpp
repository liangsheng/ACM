#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int T, n;
string s;

bool gao() {
    if (s[0] == '0' || s[n - 1] == '0') return 0;

    int c = 0;
    vector<int> a, b;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') a.push_back(i);
        else b.push_back(i), c++;
    }
    if (c % 2) return 0;
    string x(n, ' '), y(n, ' ');
    for (int i = 0; i < a.size(); i++) {
        if (i < a.size() / 2) x[a[i]] = '(', y[a[i]] = '(';
        else x[a[i]] = ')', y[a[i]] = ')';
    }
    for (int i = 0; i < b.size(); i += 2) {
        x[b[i]] = '(', x[b[i + 1]] = ')';
        y[b[i]] = ')', y[b[i + 1]] = '(';
    }
    cout << "YES\n" << x << '\n' << y << '\n';
    return 1;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        cin >> s;
        if (!gao()) cout << "NO\n";
    }
    return 0;
}
