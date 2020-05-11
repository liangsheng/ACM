#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>

#define pause cout << " press any key to continue...",  cin >> chh
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)
#define sqr(x) ((x) * (x))

using namespace std;
int chh;

const int N = 45, M = 405;

struct NODE {
    int u, v;
    string str;
} edge[M];

int  n, m, S, T;
string dis[N];

void cycle(int c) {
    int i, k, u, v;
    bool flag;
    string tmp, t;
    for (k = 0; k < c * (n - 1); k++) {
        flag = 0;
        for (i = 0; i < m; i++) {
            u = edge[i].u, v = edge[i].v, tmp = edge[i].str;
            if (dis[v] == "{") continue;
            t = tmp + dis[v];
            if (t < dis[u]) {
                dis[u] = t;
                flag = 1;
            }
        }
        if (! flag) break;
    }
}

void solve() {
    int i;
    string ans;
    for (i = 0; i < n; i++) dis[i] = "{";
    dis[T].clear();
    cycle(1);
    if (dis[S] == "{") {
        puts("NO");
        return;
    }
    ans = dis[S];
    cycle(5);
    if (dis[S] < ans) {
        puts("NO");
        return;
    }
    cout << ans << endl;
}

int main() {
    int i, j;
    char s[10];
    string ss;
    while (scanf("%d %d %d %d", &n, &m, &S, &T) != EOF) {
        if (n == 0 && m == 0 && S == 0 && T == 0) break;
        for (i = 0; i < m; i++) {
            scanf("%d %d %s", &edge[i].u, &edge[i].v, s);
            edge[i].str = s;
        }
        solve();
    }
    return 0;
}

