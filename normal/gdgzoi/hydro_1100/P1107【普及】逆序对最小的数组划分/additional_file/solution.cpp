#include <bits/stdc++.h>
#define lowbit(x) (x & (-x))
using namespace std;
typedef long long LL;

const int N = 100005;

/*----------------- 树状数组 begin ----------------*/
int a[N];

void init(int n) {
    for (int i = 1; i <= n; i++) a[i] = 0;
}

void add(int p, int v) {
    // cout << "p= " << p << ", v= " << v << '\n';
    for (; p > 0; p -= lowbit(p)) a[p] += v;
}

int query(int p, int n) {
    int ans = 0;
    for (; p <= n; p += lowbit(p)) ans += a[p];
    // cout << "p= " << P << ", ans= " << ans << '\n';
    return ans;
}

/*----------------- 树状数组 end ------------------*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T, n, k;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        vector<int> a(n);
        for (int& x : a) cin >> x;
        vector<int> c = a;
        sort(c.begin(), c.end());
        c.erase(unique(c.begin(), c.end()), c.end());
        int e = c.size();
        for (int i = 0; i < n; i++) {
            a[i] = lower_bound(c.begin(), c.end(), a[i]) - c.begin() + 1;
        }
        init(e);

        auto ok = [&](LL mid) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                LL tmp = 0, j = i;
                add(a[i], 1);
                while (i + 1 < n) {
                    LL d = tmp + query(a[i + 1] + 1, e);
                    if (d > mid) break;
                    tmp = d, add(a[++i], 1);
                }
                ++cnt;
                while (j <= i) add(a[j++], -1);
            }
            // cout << "mid= " << mid << ", cnt= " << cnt << '\n';
            return cnt <= k;
        };

        // ok(2);
        LL l = 0, r = (LL) n * (n - 1) / 2;
        while (l != r) {
            LL mid = (l + r) / 2;
            bool yes = ok(mid);
            // cout << "l= " << l << ", r= " << r << ", mid= " << mid << ' ' << yes << '\n';
            if (yes) r = mid;
            else l = mid + 1;
        }
        cout << l << '\n';
    }
    return 0;
}