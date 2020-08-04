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

pair<int, int> a[5], b[5];

bool judge() {
    sort(a, a + 5);
    FOR (i, 1, 4) {
        if (a[i].X != a[i - 1].X + 1) return 0;
    }
    //if (a[4].X < 10) return 0;
    FOR (i, 1, 4) {
        if (a[i].Y != a[i - 1].Y) return 1;
    }
    return 0;
}

pair<int, int> gao(char a[]) {
    pii t;
    int sz = strlen(a);
    if (a[sz - 1] == 'S') t.Y = 0;
    else if (a[sz - 1] == 'H') t.Y = 1;
    else if (a[sz - 1] == 'C') t.Y = 2;
    else if (a[sz - 1] == 'D') t.Y = 3;
    if (sz == 3) t.X = 10;
    else {
        if (a[0] >= '2' && a[0] <= '9') t.X = a[0] - '0';
        else {
            if (a[0] == 'J') t.X = 11;
            else if (a[0] == 'Q') t.X = 12;
            else if (a[0] == 'K') t.X = 13;
            else if (a[0] == 'A') t.X = 14;
        }
    }
    //sc2(t.X, t.Y);
    return t;
}

int gcd(int x, int y) {
    return x % y ? gcd(y, x % y) : y;
}

char s[5][10];

int main() {
    pii t;
    int ans, d;
    while (~scanf("%s %s %s %s", s[0], s[1], s[2], s[3])) {
        rep (i, 4) b[i] = gao(s[i]);
        ans = 0;
        FOR (i, 2, 14) FOR (j, 0, 3) {
            t = mp(i, j);
            if (t == b[0]) continue;
            if (t == b[1]) continue;
            if (t == b[2]) continue;
            if (t == b[3]) continue;
            FOR (k, 0, 3) a[k] = b[k];
            a[4] = t;
            if (judge()) ans++;
        }
        d = gcd(ans, 48);
        printf("%d/%d\n", ans / d, 48 / d);
    }
    return 0;
}




















