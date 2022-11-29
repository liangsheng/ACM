#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#define ANS 7777777
#define N 8
#define M 130
using namespace std;

typedef long long LL;

const int MAXN = 10, MOD = 131, MAXS = 6570;  //pow(3, 8)

int n, m, e;
int b, c[3];
int qm[M];
map<int, int> fq;

int h[MOD], size[2];

struct Mat
{
    int size;
    LL mat[M][M];

    void clr()
    {
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++) mat[i][j] = 0;
    }

    void e()
    {
        memset(mat, 0, sizeof(mat));
        for(int i = 0; i < size; i++) mat[i][i] = 1;
    }

    Mat operator * (Mat b)
    {
        int i, j, k;
        Mat c;
        c.size = size;
        c.clr();
        for (i = 0; i < size; i++)
        {
            for (k = 0; k < size; k++)
            {
                if (mat[i][k]==0) continue;
                for (j = 0; j < size; j++)
                {
                    if( b.mat[k][j] == 0) continue;
                    c.mat[i][j] += mat[i][k] * b.mat[k][j] % ANS;
                    c.mat[i][j] %= ANS;
                }
            }
        }
        return c;
    }

    Mat operator ^ (int p)          //二分求幂
    {
        int i, j;
        Mat ret, a;
        ret.size = size;
        ret.e();
        a = *this;
        while (p)
        {
            if (p & 1) ret = ret * a;
            a = a * a;
            p >>= 1;
        }
        return ret;
    }
};

struct State
{
    int mask;    //当前状态,4进制
    int nxt;          //下一个节点
    int a[M];           //当前状态的数目
} s[2][MAXS];

inline void update(int p, int mask, int a[M])
{
    int i, j, val = mask % MOD;
    for (i = h[val]; i != -1; i = s[p][i].nxt)
    {
        if (s[p][i].mask == mask)
        {
            for (j = 0; j < e; j++) s[p][i].a[j] += a[j];
            return;
        }
    }
    s[p][size[p]].mask = mask;
    for (j = 0; j < e; j++) s[p][size[p]].a[j] = a[j];
    s[p][size[p]].nxt = h[val];
    h[val] = size[p]++;
}

inline int get(int mask, int x)
{
    return (mask >> (x << 1)) & 3;
}

inline int change(int mask, int x, int val)
{
    mask = mask ^ (get(mask, x) << (x << 1));
    if (val) return mask ^ (val << (x << 1));
    return mask;
}

inline int find(int mask, int x, int val)
{
    int t = (val == 1 ? 1 : -1), b = 1;
    for (x += (val == 1) + t; x >= 0 && x <= m && b; x += t)  //方便在p == q时的寻找
    {
        int p = get(mask, x);
        if (p == val) b++;
        else if (p == 3 - val) b--;
    }
    return b ? x : x - t;
}

inline void init(int p)
{
    size[p] = 0;
    memset(h, -1, sizeof(h));
    memset(s[p], 0, sizeof(s[p]));
}

void dfs(int p)
{
    int i;
    if (p == m)
    {
        c[1] = c[2] = 0;
        for (i = 0; i < m; i++)
        {
            c[get(b, i)]++;
            if (c[2] > c[1]) return;
        }
        if (c[1] == c[2]) qm[e] = b, fq[b] = e++;
        return;
    }
    for (i = 0; i < 3; i++)
    {
        b = change(b, p, i);
        dfs(p + 1);
    }
}

int main()
{
    int i, j, k, p, q, t, tmp;
    int x, y, f;
    int a[M];
    Mat c;
    while (scanf("%d%d", &m, &n) != EOF)
    {
        e = b = 0, fq.clear();
        dfs(0);
        f = 1;
        init(f);
        fill(a, a + e, 0);
        for (i = 0; i < e; i++)
        {
            a[i] = 1;
            update(f, qm[i] << 2, a);
            a[i] = 0;
        }
        for (j = 1; j <= m; j++)
        {
            f ^= 1;
            init(f);
            for (k = 0; k < size[f ^ 1]; ++k)
            {
                p = get(s[f ^ 1][k].mask, j - 1), q = get(s[f ^ 1][k].mask, j);
                if (p == 0 && q == 0)
                {
                    if (j != m)
                        update(f, change(change(s[f ^ 1][k].mask, j - 1, 1), j, 2), s[f ^ 1][k].a);
                }
                else if (p == 0)
                {
                    if (j != m) update(f, s[f ^ 1][k].mask, s[f ^ 1][k].a);
                    update(f, change(change(s[f ^ 1][k].mask, j - 1, q), j, 0), s[f ^ 1][k].a);
                }
                else if (q == 0)
                {
                    update(f, s[f ^ 1][k].mask, s[f ^ 1][k].a);
                    if (j != m)
                        update(f, change(change(s[f ^ 1][k].mask, j - 1, 0), j, p), s[f ^ 1][k].a);
                }
                else if (p == q)
                {
                    t = find(s[f ^ 1][k].mask, j - 1, p);
                    if (t >= 0 && t <= m)
                        update(f, change(change(change(s[f ^ 1][k].mask, j - 1, 0), j, 0), t, p), s[f ^ 1][k].a);
                }
                else if (p == 2)
                    update(f, change(change(s[f ^ 1][k].mask, j - 1, 0), j, 0), s[f ^ 1][k].a);
            }
        }
        c.size = e, c.clr();
        for (i = 0; i < size[f]; i++)
        {
            p = fq[s[f][i].mask];
            for (j = 0; j < e; j++) c.mat[j][p] = s[f][i].a[j];
        }
        c = c ^ n;
        tmp = (1 << (2 * m - 1)) + 1;
        p = fq[tmp];
        if (c.mat[0][p] == 0) printf("Impossible\n");
        else printf("%d\n", c.mat[0][p]);
    }
    system("pause");
    return 0;
}
