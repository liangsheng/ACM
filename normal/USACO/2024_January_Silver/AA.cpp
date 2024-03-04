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
vector<int> a, l;
vector<pii> h;

bool gao() {
    sort(h.begin() + 1, h.begin() + q + 1, [&](const pii& u, const pii& v) {
        if (u.Y != v.Y) return u.Y < v.Y;
        return u.X < v.X; 
    });
    int maxi = 0;
    for (int i = 1; i <= q; i++) {
        // cout << "i= " << i << '\n';
        if (h[i].X < h[i - 1].Y) return false;

        auto [x, y] = h[i];
        for (int p = h[i - 1].Y + 1; p < h[i].X; p++) {
            if (a[p] == 0) a[p] = 1;
            maxi = max(maxi, a[p]);
        }
        while (i + 1 < n && h[i + 1].Y == h[i].Y) i++;
        
        int t = -1, tmp = 1;
        for (int k = x; k < y; k++) {
            if (a[k] == 0) continue;
            if (t == -1 || a[k] > tmp) t = k, tmp = a[k];
        }
        // sc2(i, tmp);
        // sc3(x, y, a[x]);
        if (a[y] != 0 && a[y] <= max(maxi, tmp)) return false;
		if (a[y] == 0) {
            if (i == q || h[i + 1].X > y) a[y] = max(maxi, tmp) + 1;
            else l[y] = max(maxi, tmp) + 1;
        }
        if (a[y] > c || l[y] > c) return false;

        if (tmp > maxi) {
            if (a[x] != 0 && a[x] < tmp) return false;
            a[x] = max(tmp, l[x]);
        }
        for (int p = x; p < y; p++) {
            a[p] = (a[p] == 0 ? max(1, l[p]) : a[p]);
            maxi = max(maxi, a[p]);
        }
        maxi = max(maxi, max(a[y], l[y]));
    }
    for (int p = h[q].Y + 1; p <= n; p++) a[p] = (a[p] == 0 ? 1 : a[p]);
    return true;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> n >> q >> c;
        a = vector<int>(n + 1, 0);
        l = vector<int>(n + 1, 0);
        h = vector<pii>(n + 1, {0, 0});
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= q; i++) cin >> h[i].X >> h[i].Y;
        
        if (!gao()) cout << -1 << '\n';
        else {
            for (int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];
        }
    }
    return 0;
}