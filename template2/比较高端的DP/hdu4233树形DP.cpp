#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define pause cout << " press any key to continue...", cin >> chh
#define file_r(x) freopen(x, "r", stdin)
#define file_w(x) freopen(x, "w", stdout)

using namespace std;
int chh;

const int N = 100005, M = 1005;

int n, m, e, root;
int head[N], w[N];
int nv[N], nxt[N];
int tmp[2][M][M], f[M], s[M];

void init() {
    e = 0;
    fill(head, head + n + 1, -1);
}

void add_edge(int u, int v) {
    nv[e] = v, nxt[e] = head[u];
    head[u] = e++;
}

void solve(int p, int sum[M]) {
    int i, tmp[M];
    memcpy(tmp, sum, sizeof(tmp));
    for (i = head[p]; i != -1; i = nxt[i]) solve(nv[i], tmp);
    for (i = m; i >= 2; i--) {
        if (sum[i - 1] > 0 && sum[i - 1] + w[p] > tmp[i])
            sum[i] = sum[i - 1] + w[p];
        else sum[i] = tmp[i];
    }
    sum[1] = max(tmp[1], w[p]);
}

void dfs() {
    int i, j, v, h, p, top = 0;
    s[top++] = root, f[top - 1] = head[root];
    memset(tmp[0][0], 0, sizeof(tmp[0][0]));
    memset(tmp[1][0], 0, sizeof(tmp[1][0]));
    while (top) {
        j = top - 1, p = s[j], h = f[j];
        //printf("p= %d", p), pause;
        if (h == -1) {
            for (i = m; i >= 2; i--) {
                if (tmp[0][j][i - 1] > 0 && tmp[0][j][i - 1] + w[p] > tmp[1][j][i])
                    tmp[0][j][i] = tmp[0][j][i - 1] + w[p];
                else tmp[0][j][i] = tmp[1][j][i];
            }
            tmp[0][j][1] = max(tmp[1][j][1], w[p]);
            if (j != 0) memcpy(tmp[1][j - 1], tmp[0][j], sizeof(tmp[1][j - 1]));
//            printf("p= %d\n", p);
//            for (i = 1; i <= m; i++) printf("%d ", tmp[0][j][i]); pause;
            top--;
        } else {
            v = nv[h];
            memcpy(tmp[0][top], tmp[1][j], sizeof(tmp[0][top]));
            memcpy(tmp[1][top], tmp[1][j], sizeof(tmp[1][top]));
            f[top] = head[v], s[top++] = v;
            f[j] = nxt[h];
        }
    }
    printf("%d\n", tmp[0][0][m]);
}

int main() {
    //file_r("in.txt");
    //file_w("out.txt");
    int i, v;
    int sum[M];
    while (scanf("%d%d", &n, &m) != EOF) {
        if (n == 0 && m == 0) break;
        init();
        for (i = 1; i <= n; i++) {
            scanf("%d%d", &v, &w[i]);
            if (v == 0) root = i;
            else add_edge(v, i);
        }
        dfs();
//        memset(sum, 0, sizeof(sum));
//        solve(root, sum);
//        printf("%d\n", sum[m]);
    }
    return 0;
}
