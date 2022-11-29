#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n;
int a[N], b[N], c[N];

void gao() {
    int p = -1, l = 0, r = n - 2;
    for (int i = 1; i <= n; i++) if (c[i] >= 3) {
        p = i;
        break;
    }
    if (p == -1) {
        for (int i = 0; i < n - 1; i++) printf("%d\n", i);
        return ;
    }
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == p || b[i] == p) printf("%d\n", l++);
        else printf("%d\n", r--);
    }
}

int main() {
    while (~scanf("%d", &n)) {
        memset(c, 0, sizeof(c));
        for (int i = 0; i < n - 1; i++) {
            scanf("%d %d", &a[i], &b[i]);
            c[a[i]]++, c[b[i]]++;
        }
        gao();
    }
    return 0;
}