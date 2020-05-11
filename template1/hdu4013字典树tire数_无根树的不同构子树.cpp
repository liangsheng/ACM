#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#define inf (1 << 30)
#define mod 1000000007
#define N 20
const double eps = 1e-12;
const double pi = acos(-1.0);
using namespace std;

struct tire
{
    int date;
    struct tire* son[2];
}*root;

int T, n, state, ans;
int a[N], b[N], vis[N];
int g[N][N];

int init()
{
    ans = 0;
    memset(g, 0, sizeof(g));
    root = new tire;
    root -> date = 0;
    root -> son[0] = NULL;
    root -> son[1] = NULL;
    return 1;
}

int insert(string s, struct tire *p)
{
    int i;
    struct tire *rot = p;
    for (i = 0; i < s.size(); i++)
    {
        if (rot -> son[s[i] - '0'] == NULL)
        {
            tire *t = new tire;
            t -> date = 0;
            t -> son[0] = NULL;
            t -> son[1] = NULL;
            rot -> son[s[i] - '0'] = t;
        }
        rot = rot -> son[s[i] - '0'];
    }
    if (rot -> date == 1) return 0;
    rot -> date = 1;
    return 1;
}

int DFS(int t)
{
    int i;
    state = state ^ (1 << t);
    vis[t] = 1;
    for (i = 0; i < n; i++)
        if (vis[i] == 0 && ((1 << i) & state)) DFS(i);
    return 1;
}

int check()
{
    int i;
    memset(vis, 0, sizeof(vis));
    for (i = 0; i < n; i++)
        if (state & (1 << i))
        {
            DFS(i);
            break;
        }
    return 1;
}

string DFS1(int t, int p)
{
    int i, j;
    string vs = "0";
    vector<string> q;
    for (i = 0; i < n; i++)
        if (vis[i] && g[t][i] && i != p) q.push_back(DFS1(i, t));
    sort(q.begin(), q.end());
    for (i = 0; i < q.size(); i++) vs += q[i];
    vs += "1";
    return vs;
}

int solve()
{
    int i, j, f = 0, t;
    string s;
    for (i = 0; i < n; i++)
        if (vis[i] == 1)
        {
            s = DFS1(i, -1);
            t = insert(s, root);
            if ((! t) && (! f)) return 0;
            f = 1;
        }
    return 1;
}

int main()
{
    int i, j, h, x, y;
    string s;
    scanf("%d", &T);
    for (h = 1; h <= T; h++)
    {
        scanf("%d", &n);
        init();
        for (i = 1; i < n; i++)
        {
            scanf("%d%d", &x, &y);
            g[x - 1][y - 1] = g[y - 1][x - 1] = 1;
        }
        for (i = 1; i < (1 << n); i++)
        {
            state = i;
            check();
            if (state != 0) continue;
            ans += solve();
        }
        printf("Case #%d: %d\n", h, ans);
    }
    system("pause");
    return 0;
}
