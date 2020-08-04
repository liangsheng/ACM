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

typedef pair<int, int> pii;
typedef long long LL;

int n, L, R;
bool f[10000005];

int main() {
    LL t;
    int ans;
    scanf("%d %d %d", &n, &L, &R);
    memset(f, 0, sizeof(f));
    if (n == 1) {
        if (L == 0) printf("1\n");
        else printf("0\n");
    } else {
        FOR (i, 0, R) {
            t = (LL) i ^ ((LL) n * i);
            if (t >= L && t <= R) f[t] = 1;
        }
        ans = 0;
        FOR (i, L, R) ans += f[i];
        printf("%d\n", ans);
    }
    return 0;
}














