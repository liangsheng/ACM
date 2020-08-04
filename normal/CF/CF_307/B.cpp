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

char s[3][N];
int a[3][26], b[26];

int main() {
//    memset(a, 0, sizeof(a));
//    a[0][0] = 1, a[0][25] = 4;
//    memcpy(b, a[0], sizeof(a[0]));
//    rep (i, 26) cout << b[i] << '\n';
    int c1, c2, x, y, flag;
    while (~scanf("%s %s %s", s[0], s[1], s[2])) {
        memset(a, 0, sizeof(a));
        rep (i, 3) {
            for (int j = 0; s[i][j]; j++) a[i][s[i][j] - 'a']++;
        }
        c1 = c2 = 0;
        for (x = 0; ; x++) {
            //sc(x);
            memcpy(b, a[0], sizeof(a[0]));
            flag = 1;
            rep (i, 26) {
                if (b[i] < a[1][i] * x) {
                    flag = 0;
                    break;
                }
                b[i] -= a[1][i] * x;
            }
            if (!flag) break;
            y = ~0U >> 2;
            rep (i, 26) {
                if (b[i] < a[2][i]) {
                    y = 0;
                    break;
                }
                if (a[2][i] == 0) continue;
                y = min(y, b[i] / a[2][i]);
                b[i] -= y * a[2][i];
            }
            //sc2(x, y);
            if (x + y > c1 + c2) c1 = x, c2 = y;
        }
        memcpy(b, a[0], sizeof(a[0]));
        //printf("%d %d\n", c1, c2);
        rep (i, 26) b[i] -= c1 * a[1][i] + c2 * a[2][i];
        rep (i, c1) printf("%s", s[1]);
        rep (i, c2) printf("%s", s[2]);
        rep (i, 26) rep (j, b[i]) printf("%c", i + 'a');
        puts("");
    }
    return 0;
}




















