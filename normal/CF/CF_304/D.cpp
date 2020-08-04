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

const int N = 5000000;

int a[N + 5], f[N + 5];
LL b[N];

void init() {
    memset(a, 0, sizeof(a));
    FOR (i, 2, N) {
        if (f[i]) continue;
        a[i] = 1;
        for (int j = i + i; j <= N; j += i) {
            int x = j, c = 0;
            while ((x % i) == 0) c++, x /= i;
            a[j] += c;
            f[j] = 1;
        }
    }
    b[0] = 0;
    FOR (i, 1, N) b[i] = b[i - 1] + a[i];
}

int T, x, y;

int main() {
    init();
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &y, &x);
        cout << b[y] - b[x] << '\n';
    }
    return 0;
}

















