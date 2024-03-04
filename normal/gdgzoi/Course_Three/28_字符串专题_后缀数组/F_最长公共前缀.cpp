#include <bits/stdc++.h>
using namespace std;

/*---------------------------------- 后缀数组 begin -----------------------*/
const int N = 1000005;

int r[N], rnk[N], sa[N], height[N];
int wa[N], wb[N], wc[N], wv[N];

int cmp(int *r ,int a, int b, int j) {
    return r[a] == r[b] && r[a + j] == r[b + j];
}

void da(int *r, int *sa, int n, int m) {
    int i, j, p, *x=wa, *y=wb, *t;
    for (i = 0; i < m; i++) wc[i] = 0;
    for (i = 0; i < n; i++) wc[x[i] = r[i]]++;
    for (i = 1; i < m; i++) wc[i] += wc[i-1];
    for (i = n - 1; i >= 0; i--) sa[--wc[x[i]]] = i;
    for (j = 1, p = 1; p < n; j *= 2, m = p) {
        for (p = 0, i = n - j; i < n; i++) y[p++] = i;
        for (i = 0; i < n; i++) if (sa[i] >= j) y[p++] = sa[i] - j;
        for (i = 0; i < n; i++) wv[i] = x[y[i]];
        for (i = 0; i < m; i++) wc[i] = 0;
        for (i = 0; i < n; i++) wc[wv[i]]++;
        for (i = 1; i < m; i++) wc[i] += wc[i - 1];
        for (i = n - 1; i >= 0; i--) sa[--wc[wv[i]]] = y[i];
        for (t = x, x = y, y = t, p = 1,x[sa[0]] = 0,i = 1; i < n; i++)
        x[sa[i]] = cmp(y, sa[i-1], sa[i], j) ? p - 1 : p++;
    }
}

void calheight(int *r, int *sa, int n) {
    int i, j, k = 0;
    // sa[0] = n, 是人为添加的, 要处理掉
    for (i = 1; i <= n; i++) rnk[sa[i]] = i;
    // sa: index range 1~n value range 0~n-1
    // rnk: index range 0~n-1 value range 1~n
    // height: index from 1~n (height[1] = 0)
    // hright[i] 存储的是: 排名第 i 的字串和排名第 i - 1 的字串的最长公共前缀的长度
    for (i = 0; i < n; height[rnk[i++]] = k)
    for (k ? k-- : 0, j = sa[rnk[i] - 1]; r[i + k] == r[j + k]; k++);
}

/*---------------------------------- 后缀数组 end -------------------------*/

/*---------------------------------- st 表 begin -------------------------*/
const int D = 20;

int ln[N] = {-1, -1};  // 一定要把 ln[1] = -1, 配合 P62 行, 多组数据时只计算一次
int st[N][D];

void cal_ln() {
    ln[1] = 0;
    for (int i = 2, j = 0, p = 2; i < N; i++) {
        if (i == p) j++, p <<= 1;
        ln[i] = j;
    }
}

void init(int n) {
    if (ln[0] == -1) cal_ln();  // 注意: 若果是多组数据, 这里 cal_ln() 只需要计算一次 
    for (int i = 1; i <= n; i++) st[i][0] = height[i];
    for (int j = 1, t = 1; j <= ln[n]; j++, t *= 2) {
        for (int i = 1; i + t * 2 - 1 <= n; i++) st[i][j] = min(st[i][j - 1], st[i + t][j - 1]);
        // for (int i = 1; i <= n - t; i++) st[i][j] = min(st[i][j - 1], st[i + t][j - 1]);
        // for (int i = n - t + 1; i <= n; i++) st[i][j] = st[i][j - 1];
    }
}

int query(int i, int j) {
    if (i == j) return st[i][0];
    if (i > j) swap(i, j);
    int m = ln[j - i];
    // int m = ln[j - i + 1];  // 这个也可以通过
    return min(st[i][m], st[j - (1 << m) + 1][m]);
}

/*---------------------------------- st 表 end ---------------------------*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    while (cin >> s) {
        int n = s.size();
        for (int i = 0; i < n; i++) r[i] = s[i] - 'a' + 1;
        r[n] = 0;
        da(r, sa, n + 1, 30);  // 总共 26 个不同的字符, 取 30 略大于 26 就行
        calheight(r, sa, n);   
        init(n);

        int m, x, y;
        cin >> m;
        while (m--) {
            cin >> x >> y;
            if (x == y) cout << n - x + 1 << '\n';
            else {
                x = rnk[x - 1], y = rnk[y - 1];
                if (x > y) swap(x, y);
                cout << query(x + 1, y) << '\n';
            }
        }
    }
    return 0;
}
