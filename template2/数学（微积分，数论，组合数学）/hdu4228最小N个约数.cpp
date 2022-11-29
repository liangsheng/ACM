#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>

#define pause cout << " press any key to continue...", cin >> chh
#define file_r(x) freopen(x, "r", stdin)
#define file_w(x) freopen(x, "w", stdout)

using namespace std;
int chh;

typedef long long LL;

const int N = 200;
const LL INF = 1e15;

int e;
int prim[N], a[N], r[N];
LL power[N][N];
bool is_prim[N];

void get_prim()
{
    int i, j;
    e = 0;
    fill(is_prim, is_prim + N, 1);
    for (i = 2; i < N; i++) {
        if (! is_prim[i]) continue;
        prim[e++] = i;
        for (j = i * i; j < N; j += i) is_prim[j] = 0;
        fill(power[i], power[i] + N, 0);
        power[i][0] = 1;
        for (j = 1; j < N; j++) {
            power[i][j] = power[i][j - 1] * i;
            if (power[i][j] > INF) {
                power[i][j] = 0;
                break;
            }
        }
    }
}

LL solve(int n, int p, bool f, int most) {
    int i, j;
    LL ans = INF, tmp, t;
    if (n == 1) return 1;
    for (i = 1; i < n; i++) {
        if (n % i != 0) continue;
        j = n / i;
        if (j - 1 <= most && (!f || j % 2)) {
            tmp = power[prim[p]][j - 1];
            if (tmp != 0) {
                t = solve(i, p + 1, f, j - 1);
                if (t < INF / tmp) {
                    tmp *= t;
                    if (tmp < ans) ans = tmp;
                }
            }
        }
    }
    return ans;
}

int main() {
    file_r("in.txt");
    file_w("out.txt");
    int n;
    LL ans;
    get_prim();
    while (scanf("%d", &n) != EOF) {
        if (n == 0) break;
        ans = min(solve(n * 2, 0, 0, n * 2), solve(n * 2 - 1, 0, 1, n * 2 - 1));
        printf("%lld\n", ans);
    }
    return 0;
}
