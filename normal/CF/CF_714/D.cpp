#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 200005;

int T, n, p;
int a[N], f[N];
vector<pair<int, int> > b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n >> p;
        b.clear();
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            b.push_back(make_pair(a[i], i));
        } 
        sort(b.begin(), b.end());

        LL ans = 0, now = n;
        memset(f, 0, sizeof(f));
        for (int k = 0; k < n; k++) {
            int v = b[k].first, id = b[k].second;
            if (v >= p) break;
            if (f[id]) continue;
            // cout << "k= " << k << ' ' << v << ' ' << id << '\n';
            int l = id, r = id;
            while ((l - 1 > 0) && (a[l - 1] % v == 0)) {
                l--;
                if (f[l]) break;
            }
            while ((r + 1 <= n) && (a[r + 1] % v == 0)) {
                r++;
                if (f[r]) break;
            }
            // cout << "l= " << l << ' ' << r << ' ' << f[l] << ' ' << f[r] << '\n';
            ans = ans + (LL) v * (r - l);
            if (f[l] + f[r] == 0) now -= r - l;
            else now -= r - l + 1;
            for (int i = l; i <= r; i++) f[i] = 1;
        }
        // cout << now << ' ' << ans << '\n';
        if (now != 1) ans += (LL) p * (now - 1);
        cout << ans << '\n';
    }
    return 0;
}