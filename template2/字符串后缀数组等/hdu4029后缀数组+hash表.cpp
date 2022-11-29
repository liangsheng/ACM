#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#define N 130
#define M 17000
#define H 30000
#define file_r(x) freopen(x, "r", stdin)
#define file_w(x) freopen(x, "w", stdout)
using namespace std;

int T, n, m, cnt;
char g[N][N];
int r[M], rank[M], sa[M], height[M];
int wa[M], wb[M], wc[M], wv[M];
int hashn[H];
char hashc[H][N];

int cmp(int *r ,int a, int b, int j)
{
    return r[a] == r[b] && r[a + j] == r[b + j];
}

int da(int *r, int *sa, int n, int m)
{
    int i, j, p, *x = wa, *y = wb, *t;
    for (i = 0; i < m; i++) wc[i] = 0;
    for (i = 0; i < n; i++) wc[x[i] = r[i]]++;
    for (i = 1; i < m; i++) wc[i] += wc[i-1];
    for (i = n - 1; i >= 0; i--) sa[--wc[x[i]]] = i;
    for (j = 1, p = 1; p < n; j *= 2, m = p)
    {
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
    return 1;
}

int calheight(int *r, int *sa, int n)
{
    int i, j, k = 0;
    //sa[0] = n, 是人为添加的, 要处理掉
    for (i = 1; i <= n; i++) rank[sa[i]] = i;
    //sa: index range 1~n value range 0~n-1
    //rank: index range 0~n-1 value range 1~n
    //height: index from 1   (height[1] = 0)
    for (i = 0; i < n; height[rank[i++]] = k)
    for (k ? k-- : 0, j = sa[rank[i] - 1]; r[i + k] == r[j + k]; k++);
    return 1;
}

int get_in(char *s, int hashkey)
{
    hashn[hashkey] = ++cnt;
    strcpy(hashc[hashkey], s);
    return cnt;
}

int find(char *s, int p1, int p2, int hashkey)
{
    int i, e = 0;
    char tmp[N];
    for (i = p1; i < p2; i++) tmp[e++] = s[i];
    tmp[e] = 0;
    while (hashn[hashkey] != 0)
    {
        if (strcmp(hashc[hashkey], tmp) == 0) return hashn[hashkey];
        hashkey = (hashkey + 1) % H;
    }
    return get_in(tmp, hashkey);
}

int main()
{
    int n, m;
    int i, j, p, h, cas = 0, ans, e, hashkey;
    char ch;
    //file_r("in.txt");
    //file_w("out.txt");
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        ans = 0;
        for (i = 0; i < n; i++) scanf("%s", g[i]);
        for (i = 1; i <= m; i++)
        {
            e = cnt = 0;
            memset(hashn, 0, sizeof(hashn));
            for (j = 0; j <= m - i; j++)
            {
                for (p = 0; p < n; p++)
                {
                    hashkey = 0;
                    for (h = j; h < j + i; h++)
                        hashkey = (hashkey * 26 + g[p][h] - 'A') % H;
                    r[e++] = find(g[p], j, j + i, hashkey);
                }
                if (j != m - i) e++;
            }
            for (p = n; p < e; p += n + 1) r[p] = ++cnt;
            r[e] = 0;
            da(r, sa, e + 1, cnt + 1);
            calheight(r, sa, e);
            for (j = 1; j <= e; j++)
                ans += n - sa[j] % (n + 1) - height[j];
        }
        printf("Case #%d: %d\n", ++cas, ans);
    }
    system("pause");
    return 0;
}
