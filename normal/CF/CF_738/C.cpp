#include <bits/stdc++.h>
using namespace std;

const int N = 10005;

int T, n;
int a[N];

void gao() {
    if (n == 1 && a[1] == 1) {
        puts("2 1");
        return ;
    }
    int c = 0;
    for (int i = 1; i <= n; i++) c += (a[i] == 0);
    if (c == n) {
        for (int i = 1; i <= n; i++) printf("%d ", i);
        printf("%d\n", n + 1);
        return ;
    }
    if (c == 0) {
        puts("-1");
        return ;
    }
    int p = -1;
    for (int i = 1; i < n; i++) if (a[i] == 0 && a[i + 1] == 1) {
        p = i;
        break;
    }
    if (p != -1) {
        for (int i = 1; i <= p; i++) printf("%d ", i);
        printf("%d ", n + 1);
        for (int i = p + 1; i < n; i++) printf("%d ", i);
        printf("%d\n", n);
        return ;
    }
    for (int i = 1; i < n; i++) if (a[i] == 1 && a[i + 1] == 0) {
        p = i;
        break;
    }
    for (int i = p + 1; i <= n + 1; i++) printf("%d ", i);
    for (int i = 1; i < p; i++) printf("%d ", i);
    printf("%d\n", p);
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        gao();
    }
    return 0;
}