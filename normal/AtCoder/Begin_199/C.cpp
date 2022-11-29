#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, m;
string s;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int cmd, a, b, now;
    while (cin >> n) {
        cin >> s;
        cin >> m;
        now = 0;
        while (m--) {
            cin >> cmd >> a >> b;
            if (cmd == 1) {
                if (now == 0) swap(s[a - 1], s[b - 1]);
                else {
                    if (a <= n) a = n + a;
                    else a = a - n;
                    if (b <= n) b = n + b;
                    else b = b - n;
                    swap(s[a - 1], s[b - 1]);
                }
            } else if (cmd == 2) now ^= 1;
        }
        if (now == 0) cout << s << '\n';
        else cout << s.substr(n, n) + s.substr(0, n) << '\n';
    }
    return 0;
}