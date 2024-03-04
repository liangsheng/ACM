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
    // height: index from 1   (height[1] = 0)
    for (i = 0; i < n; height[rnk[i++]] = k)
    for (k ? k-- : 0, j = sa[rnk[i] - 1]; r[i + k] == r[j + k]; k++);
}

/*---------------------------------- 后缀数组 end -------------------------*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    while (cin >> s) {
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] >= '0' && s[i] <= '9') r[i] = s[i] - '0' + 1;
            else if (s[i] >= 'A' && s[i] <= 'Z') r[i] = s[i] - 'A' + 11;
            else r[i] = s[i] - 'a' + 37;
        }
        r[n] = 0;
        da(r, sa, n + 1, 70);  // 总共 62 个不同的字符, 取 70 略大于 62 就行
        // calheight(r, sa, n);   
        for (int i = 1; i <= n; i++) cout << sa[i] + 1 << " \n"[i == n];     
    }
    return 0;
}