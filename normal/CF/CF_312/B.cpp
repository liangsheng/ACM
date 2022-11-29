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

const int N = 100005, M = 1000005;

int n;
int a[N], L[M], R[M], c[M];

int main() {
    int maxi, l, r;
    while (~scanf("%d", &n)) {
        memset(L, -1, sizeof(L));
        memset(R, -1, sizeof(R));
        memset(c, 0, sizeof(c));
        maxi = 0;
        rep (i, n) {
            scanf("%d", &a[i]);
            if (L[a[i]] == -1) L[a[i]] = i;
            R[a[i]] = i;
            c[a[i]]++;
            maxi = max(maxi, c[a[i]]);
        }
        l = -1, r = -1;
        FOR (i, 1, 1000000) {
            if (L[i] == -1) continue;
            if (maxi != c[i]) continue;
            if (l == -1 || R[i] - L[i] < r - l) l = L[i], r = R[i];
        }
        printf("%d %d\n", l + 1, r + 1);
    }
    return 0;
}












