#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <bitset>
#define pause cout << " press any key to continue...", cin >> ch
#define file_r(x) freopen(x, "r", stdin)
#define file_w(x) freopen(x, "w", stdout)
using namespace std;
int ch;

const int N = 305, M = 205;

int n, m;
bitset<N> a[M];

bool cmp(const bitset<N> &arg0, const bitset<N> &arg1) {
    return arg0.count() < arg1.count();
}

int main() {
    int i, j, k, x, ans;
    bitset<N> tmp;
    while (scanf("%d%d", &n, &m) != EOF) {
        if (n == 0 && m == 0) break;
        for (i = 1; i <= m; i++) a[i].reset();
        for (i = 1; i <= m; i++) {
            scanf("%d", &k);
            while (k--) {
                scanf("%d", &x);
                a[i].set(x);
            }
        }
        sort(a + 1, a + m + 1, cmp);
        ans = 0;
        for (i = 1; i <= m; i++) {
            tmp.reset();
            for (j = 1; j < i; j++) {
                if ((a[i] | a[j]) == a[i]) tmp |= a[j];
            }
            if (tmp == a[i]) ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
