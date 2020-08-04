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

LL n, k;
LL a[55];

void gao(LL p, LL n, LL k) {
    //sc3(p, n, k);
    if (n == 0) return ;
    if (n == 1) {
        cout << p;
        return ;
    }
    if (k > a[n - 1]) {
        cout << p + 1 << ' ' << p << ' ';
        gao(p + 2, n - 2, k - (a[n - 1]));
    } else {
        cout << p << ' ';
        gao(p + 1, n - 1, k);
    }
}

int main() {
    a[1] = 1, a[2] = 2, a[3] = 3, a[4] = 5;
    FOR (i, 5, 50) a[i] = a[i - 2] + a[i - 1];
    while (cin >> n >> k) {
        if (n == 1) {
            puts("1");
            continue;
        }
        gao(1, n, k);
        puts("");
    }
    return 0;
}


















