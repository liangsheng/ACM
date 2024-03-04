#include <bits/stdc++.h>
using namespace std;

/*---------------------------------- 后缀数组 begin -----------------------*/
const int N = 400105;

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

int ln[N] = {-1, -1};  // 一定要把 ln[1] = -1, 配合 P64 行, 多组数据时只计算一次
int st[N][D];

void cal_ln() {
    // ln[1] = 0;
    // for (int i = 2, j = 0, p = 2; i < N; i++) {
    //     if (i == p) j++, p <<= 1;
    //     ln[i] = j;
    // }
	ln[0] = -1;
	for (int i = 1; i < N; i++) ln[i] = ln[i / 2] + 1;
}

void init(int n) {
    if (ln[1] == -1) cal_ln();  // 注意: 若果是多组数据, 这里 cal_ln() 只需要计算一次 
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
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<string> s(n);
    vector<vector<int>> g(n, vector<int>(n, 0));

    int e = 0;
    vector<int> u(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        u[i] = e;
        for (int j = 0; j < (int) s[i].size(); j++) r[e++] = s[i][j] - 'a' + 1;
        r[e++] = 27;
    }
    r[e] = 0;
    da(r, sa, e + 1, 30);  // 总共 26 个不同的字符, 取 30 略大于 26 就行
    calheight(r, sa, e);   
    init(e);
    cout << query(u[0] + 2, u[2]);
    return 0;
}