#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define N 100005
using namespace std;

int r[N], rank[N], sa[N], height[N];
int wa[N], wb[N], wc[N], wv[N];

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

typedef pair<int ,int> PAIR;

int n, t;
int q[N];
char s[N];
vector<string> ans;

int main()
{
    int i, j, head, tail, mini, maxi, v;
    string str;
    while (scanf("%d", &t) != EOF)
    {
        scanf("%s", s);
        n = strlen(s);
        for (i = 0; i < n; i++) r[i] = s[i] - 'a' + 1;
        r[n] = 0;
        da(r, sa, n + 1, 30);
        calheight(r, sa, n);
        height[0] = height[n + 1] = 0;
        ans.clear();
        if (t == 1)
        {
            for (i = 1; i <= n; i++)
            {
                maxi = max(height[i], height[i + 1]);
                if (sa[i] + maxi >= n) continue;
                str.clear();
                for (j = 0; j <= maxi; j++) str.push_back(s[sa[i] + j]);
                ans.push_back(str);
            }
            if (ans.empty()) printf("impossible\n");
            else
            {
                sort(ans.begin(), ans.end());
                cout << ans[0] << endl;
            }
            continue;
        }
        head = tail = 0;
        t--;
        for (i = 2; i <= n; i++)
        {
            while (head < tail && height[i] < height[q[tail - 1]]) tail--;
            q[tail++] = i;
            while (head < tail && q[head] < i - t + 1) head++;
            if (i < t + 1) continue;
            v = q[head];
            mini = height[q[head]];
            if (mini == 0) continue;
            if (height[i - t] < mini && height[i + 1] < mini)
            {
                if (sa[v] + mini - 1 >= n) continue;
                str.clear();
                for (j = 0; j < mini; j++) str.push_back(s[sa[v] + j]);
                ans.push_back(str);
            }
        }
        if (ans.empty()) printf("impossible\n");
        else
        {
            sort(ans.begin(), ans.end());
            cout << ans[0] << endl;
        }
    }
    return 0;
}
