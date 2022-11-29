#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

const int N = 200005;

int n, e;
vector<int> h[N];

LL gao() {
    int x = 0, y = 0, l, r;
    LL wl = 0, wr = 0, tl, tr;
    for (int i = 1; i <= e; i++) {
        if (h[i].empty()) continue;
        l = h[i][0], r = h[i].back();
        tl = min(wl + abs(r - x), wr + abs(r - y)) + r - l;
        tr = min(wl + abs(l - x), wr + abs(l - y)) + r - l;
        x = l, y = r;
        wl = tl, wr = tr;
    }
    return min(wl + abs(x), wr + abs(y));
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int x, c;
    while (cin >> n) {
        e = 0;
        for (int i = 1; i < N; i++) h[i].clear();
        for (int i = 1; i <= n; i++) {
            cin >> x >> c;
            h[c].push_back(x);
            e = max(e, c);
        }
        for (int i = 1; i <= e; i++) sort(h[i].begin(), h[i].end());
        cout << gao() << '\n';
    }
    return 0;
}