#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define N 40010
using namespace std;

int k, p;
int r[N], rank[N], sa[N], height[N];
int wa[N], wb[N], wc[N], wv[N];
vector<int> q;

int cmp(int *r ,int a, int b, int j)
{
    return r[a] == r[b] && r[a + j] == r[b + j];
}

int da(int *r, int *sa, int n, int m)
{
    int i, j, p, *x=wa, *y=wb, *t;
    for (i = 0; i < m; i++) wc[i] = 0;
    for (i = 0; i < n; i++) wc[x[i] = r[i]]++;
    for (i = 1; i < m; i++) wc[i] += wc[i-1];
    for (i = n-1; i >= 0; i--) sa[--wc[x[i]]] = i;
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

bool judge(int mid, int n)
{
    //cout << mid, system("pause");
    int i, t1 = 0;
    p = 0;
    bool f = false;
    for (i = 1; i <= n + 1; i++)
    {
        if (height[i] < mid)
        {
            if (i - t1 >= k) q.push_back(p), f = true;//, cout << "i=" << i << "p=" << p, system("pause");
            t1 = i;
            p = sa[i];
        }
        else p = max(p, sa[i]);
    }
    return f;
}

int main()
{
    int i, j, n, low, high, mid, pp;
    string s;
    while (scanf("%d", &k) != EOF)
    {
        if (k == 0) break;
        cin >> s;
        n = s.size();
        if (k == 1)
        {
            printf("%d %d\n", n, 0);
            continue;
        }
        for (i = 0; i < n; i++) r[i] = s[i] - 'a' + 1;
        r[n] = 0;
        da(r, sa, n + 1, 30);
        calheight(r, sa, n);
        height[n + 1] = 0;
        low = 0, high = n;
        q.clear();
        //judge(26, n);
        while (low < high)
        {
            mid = (low + high + 1) >> 1;
            if (judge(mid, n))
            {
                low = mid;
                pp = -999999;
                for (i = 0; i < q.size(); i++) pp = max(pp, q[i]);
                q.clear();
            }
            else high = mid - 1;
        }
        if (low == 0) printf("none\n");
        else printf("%d %d\n", low, pp);
    }
    system("pause");
    return 1;
}
