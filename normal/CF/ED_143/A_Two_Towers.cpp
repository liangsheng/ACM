#include <bits/stdc++.h>
using namespace std;

int T, n, m;
string a, b;

bool gao() {
    for (int i = b.size() - 1; i >= 0; i--) a.push_back(b[i]);
    int c = 0;
    for (int i = 1; i < a.size(); i++) c += (a[i] == a[i - 1]);
    return c <= 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n >> m;
        cin >> a >> b;
        cout << (gao() ? "YES" : "NO") << '\n';
    }
    return 0;
}