#include <bits/stdc++.h>
#define sc1(x) cout << #x << "= " << x << '\n'
#define sc2(x, y) cout << #x << "= " << x << ", " << #y << "= " << y << '\n'
#define sc3(x, y, z) cout << #x << "= " << x << ", " << #y << "= " << y << ", " << #z << "= " << z << '\n'
#define over cout << "over" << '\n'
#define X first
#define Y second
using namespace std;
typedef pair<int, int> pii;

int T, n, q, c;
vector<int> a, b, l, r;
vector<pii> h;

bool gao() {
    b = vector<int>(n + 1, 0);
    l = vector<int>(n + 1, 0);
    r = vector<int>(n + 1, 0);
    sort(h.begin() + 1, h.begin() + q + 1);
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) l[i] = 1, r[i] = c;
        else l[i] = a[i], r[i] = a[i];
    }
    int p = 1, maxi = 0;
    for (int i = 1; i <= q; i++) {
        auto [x, y] = h[i];
        // sc3(i, x, y);
        if (!(x >= h[i - 1].Y || y == h[i - 1].Y)) return false;
        // if (y < max(x + 1, h[i - 1].Y)) return false;
        // 两段之间的空隙, 直接填最小的值
        for (; p < x; p++) {
            if (l[p] > r[p]) return false;
            b[p] = l[p];
            maxi = max(maxi, b[p]);
        }
        if (a[y] != 0) r[x] = min(r[x], a[y] - 1);
        for (int j = x + 1; j < y; j++) {
            if (l[j] > maxi) l[x] = max(l[x], l[j]);
        }
        // sc3(x, l[x], r[x]);
        if (l[x] > r[x]) return false;
        b[x] = l[x];
        maxi = max(maxi, b[x]);
        l[y] = max(l[y], maxi + 1);
        // sc2(maxi, l[y]);
        for (int j = x + 1; j < y; j++) r[j] = min(r[j], maxi);
    }
    for (; p <= n; p++) {
        // sc3(p, l[p], r[p]);
        if (l[p] > r[p]) return false;
        b[p] = l[p];  
    }
    return true;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> n >> q >> c;
        a = vector<int>(n + 1, 0);
        h = vector<pii>(n + 1, {0, 0});
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= q; i++) cin >> h[i].X >> h[i].Y;
        
        if (!gao()) cout << -1 << '\n';
        else {
            for (int i = 1; i <= n; i++) cout << b[i] << " \n"[i == n];
        }
    }
    return 0;
}