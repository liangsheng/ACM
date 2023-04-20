#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a = "FBFFBFFBFBFFBFFBFBFFBFFBFBFFBFFB", s;
    int T, n, m = a.size();
    set<string> h;
    for (int d = 1; d <= 10; d++) for (int i = 0; i + d <= m; i++) h.insert(a.substr(i, d));
    // cout << h.size() << '\n';
    cin >> T;
    while (T--) {
        cin >> n >> s;
        cout << (h.count(s) ? "YES" : "NO") << '\n';
    }
    return 0;
}