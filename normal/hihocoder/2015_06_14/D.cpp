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

typedef pair<int, int> pii;
typedef long long LL;

const int N = 205, M = 100005;

int n, e, m;
int a[N];

void dfs(int id, int t) {
    if (t == 1) {
        printf("E %d\n", e++);
        return ;
    }
    printf("C 0 %d %d\n", m + 1, m + 2);
    m += 2;
    dfs(m - 2, t / 2);
    dfs(m - 1, t / 2);
}

int main() {
    int ans;
    FOR (i, 0, 7) a[i] = 1 << i;
    int x, y;
    while (~scanf("%d", &n)) {
        if (n == 2) {
            printf("1 2 1 2\n");
            printf("3\n");
            printf("C 0 1 2\n");
            printf("E 0\n");
            printf("E 1\n");
            continue;
        }
        x = -1, y = -1;
        FOR (i, 0, 7) FOR (j, 0, 7) {
            if (a[i] + a[j] == n) x = i, y = j;
        }
        if (x == -1) {
            puts("NO");
            continue;
        }
        puts("YES");
        printf("%d %d %d %d\n", a[x], n, 1, 2);
        ans = 2 * n - 1;
        printf("%d\n", ans);
        printf("C 0 1 %d\n", 2 * a[x]);
        e = 0, m = 1;
        dfs(m, a[x]);
        m = 2 * a[x];
        dfs(m, a[y]);
    }
    return 0;
}




















