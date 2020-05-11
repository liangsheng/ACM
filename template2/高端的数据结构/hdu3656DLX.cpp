#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>
#include <cmath>

#define pause cout << " press any key to continue...",  cin >> chh
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)
#define sqr(x) ((x) * (x))

using namespace std;
int chh;

const int N = 55, head = 0, V = N * N;
const double eps = 1e-7;

int T, n;
int px[N], py[N];
double dis[N][N];

int size, Limit;
int R[V], L[V], U[V], D[V], C[V];
int S[V], H[V];

int Remove(int c) {
    int i;
    for (i = D[c]; i != c; i = D[i])
        L[R[i]] = L[i], R[L[i]] = R[i];
    return 1;
}

int Resume(int c) {
    int i;
    for (i = U[c]; i != c; i = U[i])
        L[R[i]] = R[L[i]] = i;
    return 1;
}

int h() {
    int r = 0, i, j, k;
    int hash[N];
    memset(hash, 0, sizeof(hash));
    for (i = R[head]; i != head; i = R[i]) {
        if (!hash[i]) {
            r++;
            hash[i] = 1;
            for (j = D[i]; j != i ; j = D[j])
                for (k = R[j] ; k !=j ; k = R[k]) hash[C[k]] = 1;
        }
    }
    return r;
}

int Dance(int k) {
    int i, j, min, c;
    if (k + h() > Limit) return 0;
    if (R[head] == head) return 1;
    for (i = R[head], c = 0, min = N; i != head; i = R[i])
        if (S[i]<min) min = S[i], c = i;
    for (i = D[c]; i != c; i = D[i]) {
        Remove(i);
        for (j = R[i]; j != i; j = R[j]) Remove(j);
        if (Dance(k + 1)) return 1;
        for (j = L[i]; j != i; j = L[j]) Resume(j);
        Resume(i);
    }
    return 0;
}

void Link(int r, int c) {
    S[c]++, C[size] = c;
    U[size] = U[c], D[U[c]] = size;
    D[size] = c, U[c] = size;
    if (H[r] == -1) L[size] = R[size] = H[r] = size;
    else {
        L[size] = L[H[r]], R[L[H[r]]] = size;
        R[size] = H[r], L[H[r]] = size;
    }
    size++;
}

bool solve(double mid) {
    int i, j;
    for (i = 0; i <= n; i++) {
        S[i] = 0, U[i] = D[i] = i;
        R[i] = i + 1, L[i + 1] = i;
    }
    L[0] = n, R[n] = 0, size = n + 1;
    memset(H, -1, sizeof(H));
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            if (dis[i][j] <= mid) Link(i, j);
    }
    for (i = 1; i <= n; i++)
        if (S[i] == 0) return 0;
    return Dance(0);
}

int main() {
    int i, j, l, r, mid, e;
    double a[N * N];
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &Limit);
        for (i = 1; i <= n; i++) scanf("%d %d", &px[i], &py[i]);
        e = 0;
        for (i = 1; i <= n; i++) {
            for (j = i; j <= n; j++) {
                dis[i][j] = dis[j][i] = sqrt(sqr(px[i] - px[j]) + sqr(py[i] - py[j]));
                a[e++] = dis[i][j];
            }
        }
        sort(a, a + e);
        e = unique(a, a + e) - a;
        l = 0, r = e - 1;
        while (l != r) {
            mid = (l + r) >> 1;
            if (solve(a[mid])) r = mid;
            else l = mid + 1;
        }
        printf("%.6lf\n", a[l]);
    }
    return 0;
}
