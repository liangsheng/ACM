#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define pause cout << " press any key to continue...",  cin >> chh
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)
#define lowbit(x) ((x) & (-(x)))

using namespace std;
int chh;

const int N = 200005;

char str[N];
int sa[N]; //index range 1~n value range 0~n-1
int rank[N]; //index range 0~n-1 value range 1~n
int height[N]; //index from 1   (height[1] = 0)
int r[N], wa[N], wb[N], wc[N], wv[N];

int cmp(int *r, int a, int b, int j) {
	return r[a] == r[b] && r[a + j] == r[b + j];
}

void da(int *r, int *sa, int n, int m) {
	int i, j, p, *x = wa, *y = wb, *t;
	for (i = 0; i < m; i++) wc[i] = 0;
	for (i = 0; i < n; i++) wc[x[i] = r[i]]++;
	for (i = 1; i < m; i++) wc[i] += wc[i - 1];
	for (i = n - 1; i >= 0; i--) sa[--wc[x[i]]] = i;
	for (j = 1, p = 1; p < n; j *= 2, m = p) {
		for (p = 0, i = n - j; i < n; i++) y[p++] = i;
		for (i = 0; i < n; i++) if (sa[i] >= j) y[p++] = sa[i] - j;
		for (i = 0; i < n; i++) wv[i] = x[y[i]];
		for (i = 0; i < m; i++) wc[i] = 0;
		for (i = 0; i < n; i++) wc[wv[i]]++;
		for (i = 1; i < m; i++) wc[i] += wc[i - 1];
		for (i = n - 1; i >= 0; i--) sa[--wc[wv[i]]] = y[i];
		for (t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i++) {
			x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
		}
	}
}

void calheight(int *r, int *sa, int n) {
	int i, j, k = 0;
    //sa[0] = n, 是人为添加的, 要处理掉
    for (i = 1; i <= n; i++) rank[sa[i]] = i;
    //sa: index range 1~n value range 0~n-1
    //rank: index range 0~n-1 value range 1~n
    //height: index from 1   (height[1] = 0)
	for (i = 0; i < n; height[rank[i++]] = k) {
		for (k ? k-- : 0, j = sa[rank[i] - 1]; r[i + k] == r[j + k]; k++);
	}
}

int T, n;

int ln[N];
int s[N][20];

void init() {
    int i, j, t, m = ln[n];
    for (i = 1; i <= n; i++) s[i][0] = height[i];
    for (j = t = 1; j <= m; j++, t *= 2) {
        for (i = 1; i <= n - t; i++) s[i][j] = min(s[i][j - 1], s[i + t][j - 1]);
        for (i = n - t + 1; i <= n; i++) s[i][j] = s[i][j - 1];
    }
}

int find(int i, int j) {
    if (i == j) return height[i];
    if (i > j) swap(i, j);
    int m = ln[j - i];
    return min(s[i][m], s[j - (1 << m) + 1][m]);
}

int main() {
    int i, j, p;
    ln[1] = 0, j = 0, p = 2;
    for (i = 2; i < N; i++) {
        if (i == p) j++, p <<= 1;
        ln[i] = j;
    }
    scanf("%d", &T);
    while (T--) {
        scanf("%s", str);
        n = strlen(str);
        for (i = 0; i < n; i++) r[i] = str[i] - 'a' + 1;
        for (i = 0; i < n; i++) r[i + n] = str[i] - 'a' + 1;
        n = n * 2;
        r[n] = 0;
        da(r, sa, n + 1, 28);
        calheight(r, sa, n);
        init();
        p = -1;
        for (i = 1; i <= n; i++) {
            if (sa[i] >= n / 2) continue;
            if (p == -1) p = i;
            else {
                j = find(p + 1, i);
                if (j >= n / 2 && sa[i] < sa[p]) p = i;
            }
        }
        printf("%d\n", sa[p] + 1);
    }
    return 0;
}
