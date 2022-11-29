#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define rep(i, n) for (int i = 0; i < (n); i++)
#define FOR(i, n, m) for (int i = (n); i <= (m); i++)
#define repit(i, c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define sc(x) cout << #x" = " << x << endl, system("pause")
#define sc2(x, y) cout << #x" = " << x << " " << #y" = " << y << endl, system("pause")

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 105, M = -2139062144;

int n, e;
int r[N], p[N], d[N * 2];
map<pii, int> dp[N];
vi g[N];

void get_max(int &x, int y) {
    x = max(x, y);
}

int gao(int x, int id) {
    int ans = ceil(x * 1.0 / 1000) * 666 * id;
    //sc(ans);
    return ans;
}

void dfs(int u, int fa) {
    //cout << "u= " << u << " " << fa << '\n';
    //system("pause");
    int v, maxi, mini, now = 0, pre = 1;
    map<pii, int> t[2];
    repit (it, g[u]) {
        v = *it;
        if (v == fa) continue;
        dfs(v, u);
        swap(now, pre);
        if (t[pre].size() == 0) t[now] = dp[v];
        else {
            t[now].clear();
            repit (i, dp[v]) repit (j, t[pre]) {
                mini = min(i->X.X, j->X.X);
                maxi = max(i->X.Y, j->X.Y);
                if (!t[now].count(mp(mini, maxi))) t[now][mp(mini, maxi)] = i->Y + j->Y;
                else get_max(t[now][mp(mini, maxi)], i->Y + j->Y);
            }
        }
    }
    repit (i, t[now]) {
        mini = min(i->X.X, r[u]);
        maxi = max(i->X.Y, r[u]);
        if (!dp[u].count(mp(mini, maxi))) dp[u][mp(mini, maxi)] = i->Y + r[u] - gao(maxi - mini, u);
        else get_max(dp[u][mp(mini, maxi)], i->Y + r[u] - gao(maxi - mini, u));

        mini = min(i->X.X, p[u]);
        maxi = max(i->X.Y, p[u]);
        if (!dp[u].count(mp(mini, maxi))) dp[u][mp(mini, maxi)] = i->Y + p[u] - gao(maxi - mini, u);
        else get_max(dp[u][mp(mini, maxi)], i->Y + p[u] - gao(maxi - mini, u));
    }
    if (dp[u].size() == 0) {
        dp[u][mp(r[u], r[u])] = r[u];
        dp[u][mp(p[u], p[u])] = p[u];
    }
//    repit (i, dp[u]) {
//        printf("mini= %d %d %d\n", d[i->X.X], d[i->X.Y], i->Y);
//    }
//    system("pause");
}

int main() {
    int i, x, y, ans;
    //e = 0;
    scanf("%d", &n);
   // d[e++] = 0;
    for (i = 1; i <= n; i++) {
        scanf("%d %d", &r[i], &p[i]);
        //d[e++] = r[i], d[e++] = p[i];
    }
    for (i = 1; i < n; i++) {
        scanf("%d %d", &x, &y);
        g[x].pb(y);
        g[y].pb(x);
    }
//    sort(d, d + e);
//    e = unique(d, d + e) - d;
//    for (i = 1; i <= n; i++) {
//        r[i] = lower_bound(d, d + e, r[i]) - d;
//        p[i] = lower_bound(d, d + e, p[i]) - d;
//    }
    dfs(1, -1);
    ans = M;
    repit (it, dp[1]) ans = max(ans, it->Y);
    printf("%d\n", ans);
    return 0;
}











