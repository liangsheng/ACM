#include <bits/stdc++.h>

#define file_r(x) freopen(x, stdin, "r")
#define file_w(x) freopen(x, stdout, "w")
#define rep(i, n) for (int i = 0; i < n; i++)
#define FOR(i, n, m) for (int i = n; i <= m; i++)
#define repe(i, u) for (int i = head[u]; ~i; i = nxt[i])
#define FORD(i, n, m) for (int i = n; i >= m; i--)
#define repit(i, c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define pause cout << " press ant key to continue...", cin >> chh

#define pb push_back
#define mp make_pair
#define ins insert
#define X first
#define Y second
#define be begin
#define nb rbegin
#define er erase
#define SZ(c) c.size()

#define sc(n) cout << #n << "= " << n, system("pause")
#define sc2(n, m) cout << #n << "= " << n << " " << #m << "= " << m, system("pause")
#define sc3(n, m, k) cout << #n << "= " << n << " " << #m << "= " << m << " " << #k << "= " << k, system("pause")
#define sc4(n, m, k, b) cout << #n << "= " << n << " " << #m << "= " << m << " " << #k << "= " << k << " " << #b << "= " << b, system("pause")

using namespace std;
int chh;

typedef long long LL;

const int N = 100005;

int n, m;
int a[N], b[N];
LL tol;

bool ok(LL mid) {
    int p = 0;
    LL now, sum;
    memcpy(b, a, sizeof(a));
    sum = 0;
    rep (i, m) {
        now = p + 1;
        while (p < n && b[p] + now <= mid) {
            now += b[p];
            sum += b[p];
            b[p] = 0;
            p++;
            if (now == mid) break;
            now++;
        }
        if (sum == tol) return 1;
        b[p] -= mid - now;
        sum += mid - now;
    }
    return 0;
}

int main() {
    int ans;
    LL l, r, mid;
    while (~scanf("%d %d", &n, &m)) {
        l = 0, r = n, tol = 0;
        rep (i, n) {
            scanf("%d", &a[i]);
            r += (LL) a[i];
            tol += a[i];
        }
        while (l != r) {
            mid = (l + r) >> 1LL;
            if (ok(mid)) r = mid;
            else l = mid + 1;
        }
        cout << l << '\n';
    }
    return 0;
}
