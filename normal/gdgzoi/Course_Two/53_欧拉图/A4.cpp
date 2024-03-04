#include <bits/stdc++.h>
#define repe(i, u) for (int i = head[u]; i != -1; i = nxt[i])
using namespace std;

const int N = 10, M = 205;

int n, m, e, cnt;
int head[N], d[N];
int pnt[M], nxt[M], wv[M], ok[M];
int path[M];

void init() {
    e = 0, cnt = 0;
    memset(head, -1, sizeof(head));
    memset(d, 0, sizeof(d));
}

void add_edge(int u, int v, int w) {
    pnt[e] = v, wv[e] = w, ok[e] = 0;
    nxt[e] = head[u], head[u] = e++;
}

void dfs(int u) {
    repe (i, u) if (!ok[i]) {
        ok[i] = 1, ok[i ^ 1] = 1;
        dfs(pnt[i]);
        path[cnt++] = i;
    }
}

bool solve(int m) {
    int s = -1, c = 0;
    // 点从 0 到 n - 1
    for (int i = 0; i < 7; i++) {
        if (d[i] & 1) c++, s = i;
        if (d[i] > 0 && s == -1) s = i; 
    }
    if (c != 0 && c != 2) return false;
    dfs(s);
    // 判断是不是用上了所有边
    if (cnt != m) return false;
    return true;
}

int main() {
    int x, y;
    cin >> n;
    init();
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        add_edge(x, y, i);
        add_edge(y, x, -i);
        d[x]++, d[y]++;
    }
    if (!solve(n)) {
        printf("No solution\n");
    } else {
        for (int i = 0; i < cnt; i++) {
            int id = path[i];
            if (wv[id] > 0) cout << wv[id] << " -" << '\n';
            else cout << -wv[id] << " +" << '\n';
        }
    }
    return 0;
}