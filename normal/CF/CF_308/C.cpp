#include <bits/stdc++.h>

#define file_r(x) freopen(x, stdin, "r")
#define file_w(x) freopen(x, stdout, "w")
#define rep(i, n) for (int i = 0; i < n; i++)
#define FOR(i, n, m) for (int i = n; i <= m; i++)
#define repe(i, u) for (int i = head[u]; ~i; i = nxt[i])
#define FORD(i, n, m) for (int i = n; i >= m; i--)
#define repit(i, c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define pause cout << " press ant key to continue...", cin >> chh

#define pb push_back
#define mp make_pair
#define ins insert
#define X first
#define Y second
#define be begin
#define nb rbegin
#define er erase
#define SZ(c) c.size()

#define sc(n) cout << #n << "= " << n, system("pause")
#define sc2(n, m) cout << #n << "= " << n << " " << #m << "= " << m, system("pause")
#define sc3(n, m, k) cout << #n << "= " << n << " " << #m << "= " << m << " " << #k << "= " << k, system("pause")
#define sc4(n, m, k, b) cout << #n << "= " << n << " " << #m << "= " << m << " " << #k << "= " << k << " " << #b << "= " << b, system("pause")

using namespace std;
int chh;

typedef long long LL;

int w, m, p, flag;
int a[105], c[20];

void dfs(int id) {
    if (flag) return ;
    if (id == p) {
        flag = 1;
        return ;
    }
    if (c[id] == 0) dfs(id + 1);
    else if (c[id] == 1) {
        if (a[id] == 0) return ;
        a[id] = 0;
        dfs(id + 1);
        a[id] = 1;
    } else if (c[id] == w - 1) {
        if (a[id] == 1 && a[id + 1] == 1) {
            a[id] = 0, a[id + 1] = 0;
            dfs(id + 1);
            a[id] = 1, a[id + 1] = 1;
        }
        if (a[id] == 1) {
            a[id] = 0, c[id + 1] += 1;
            dfs(id + 1);
            a[id] = 1, c[id + 1] -= 1;
        }
    } else if (c[id] == w) {
        c[id] = 0, c[id + 1] += 1;
        dfs(id + 1);
        c[id] = w, c[id + 1] -= 1;
    }
}

int main() {
    int d;
    while (cin >> w >> m) {
        if (w == 2 || w == 3) {
            puts("YES");
            continue;
        }
        flag = 1, p = 0;
        FOR (i, 0, 102) a[i] = 1;
        while (m) {
            d = m % w;
            if (d != 0 && d != 1 && d != w - 1) {
                flag = 0;
                break;
            }
            c[p++] = d;
            m = (m - d) / w;
        }
        if (!flag) {
            puts("NO");
            continue;
        }
        flag = 0;
        dfs(0);
        puts(flag ? "YES" : "NO");
    }
    return 0;
}















