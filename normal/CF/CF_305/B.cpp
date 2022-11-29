#include <bits/stdc++.h>

#define file_r(x) freopen(x, stdin, "r")
#define file_w(x) freopen(x, stdout, "w")
#define rep(i, n) for (int i = 0; i < n; i++)
#define FOR(i, n, m) for (int i = n; i <= m; i++)
#define repe(i, u) for (int i = head[u]; ~i; i = nxt[i])
#define FORD(i, n, m) for (int i = n; i >= m; i--)
#define repit(i, c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define pause cout << " press ant key to continue...", cin >> chh
#define lowbit(x) ((x) & (-x))

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

const int N = 200005;

int n;
pair<int, int> a[N];
int b[N], c[N];
set<int> s;
set<int> :: iterator it1, it2, it;

void add(int x, int y) {
    for (; x > 0; x -= lowbit(x)) b[x] = max(b[x], y);
}

int gao(int x) {
    int ans = 0;
    for (; x <= n; x += lowbit(x)) ans = max(ans, b[x]);
    return ans;
}

int main() {
    int l, r;
    while (~scanf("%d", &n)) {
        FOR (i, 1, n) scanf("%d", &a[i].X), a[i].Y = i;
        sort(a + 1, a + n + 1);
        s.clear();
        s.insert(0), s.insert(n + 1);
//        memset(b, 0, sizeof(b));
//        FOR (i, 1, n) {
//            s.insert(a[i].Y);
//            it = s.find(a[i].Y);
//            it1 = it, it2 = it;
//            it1--, it2++;
//            l = *it1, r = *it2;
//            add(r - l - 1, a[i].X);
//        }
//        FOR (i, 1, n) printf("%d\n", gao(i));

        memset(c, 0, sizeof(c));
        FOR (i, 1, n) {
            s.insert(a[i].Y);
            it = s.find(a[i].Y);
            it1 = it, it2 = it;
            it1--, it2++;
            l = *it1, r = *it2;
            c[r - l - 1] = a[i].X;
        }
        FORD (i, n - 1, 1) c[i] = max(c[i], c[i + 1]);
        FOR (i, 1, n) printf("%d\n", c[i]);
    }
    return 0;
}
















