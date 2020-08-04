#include <bits/stdc++.h>

#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)
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

const int N = 1005, M = 1000000005;

LL T, n, m;
LL a[N];

int main() {
    file_r("B-large-practice.in");
    file_w("B-large-practice.out");
    LL i, j, cas = 0, l, r, mid, sum, p, ans;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (i = 1; i <= n; i++) cin >> a[i];
        l = 0, r = 100000000000000LL;
        while (l != r) {
            mid = (l + r) >> 1;
            sum = 0;
            for (i = 1; i <= n; i++) {
                sum += mid / a[i] + 1;
            }
            if (sum >= m) r = mid;
            else l = mid + 1;
        }
        sum = 0;
        for (i = 1; i <= n; i++) {
            sum += l / a[i] + (l % a[i] != 0);
        }
        for (i = 1; i <= n; i++) {
            sum += (l % a[i]) == 0;
            if (sum == m) break;
        }
        cout << "Case #" << ++cas << ": " << i << '\n';
    }
    return 0;
}

















