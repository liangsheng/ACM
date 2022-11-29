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

const int N = 1000005;

LL n, h1, a1, x1, y1, h2, a2, x2, y2;

pair<LL, LL> gao(LL h, LL a, LL x, LL y) {
    pair<LL, LL> ans = mp(-1, -1);
    FOR (i, 0, 4 * n) {
        if (h == a) {
            if (ans.X == -1) ans.X = i;
            else if (ans.Y == -1) {
                ans.Y = i;
                break;
            }
        }
        h = (x * h + y) % n;
    }
    return ans;
}

LL extgcd(LL a, LL b, LL & x, LL & y){
    if (b == 0) { x=1; y=0; return a; }
    LL d = extgcd(b, a % b, x, y);
    LL t = x; x = y; y = t - a / b * y;
    return d;
}

int main() {
    LL p, q, w;
    pair<LL, LL> a, b;
    while (cin >> n) {
        cin >> h1 >> a1 >> x1 >> y1;
        cin >> h2 >> a2 >> x2 >> y2;
        a = gao(h1, a1, x1, y1);
        b = gao(h2, a2, x2, y2);
       // sc2(a.X, a.Y);
       // sc2(b.X, b.Y);
        if (a.X == -1 || b.X == -1) {
            puts("-1");
            continue;
        }
        if (a.X == b.X) {
            cout << a.X << '\n';
            continue;
        }
        if (a.Y == -1 && b.Y == -1) {
            puts("-1");
            continue;
        }
        if (a.Y == -1 && b.Y != -1) {
            p = a.X - b.X;
            q = b.Y - b.X;
            if (p > 0 && (p % q == 0)) cout << a.X << '\n';
            else puts("-1");
            continue;
        }
        if (a.Y != -1 && b.Y == -1) {
            p = b.X - a.X;
            q = a.Y - a.X;
            if (p > 0 && (p % q == 0)) cout << b.X << '\n';
            else puts("-1");
            continue;
        }
        if (a.X > b.X) swap(a, b);
        p = a.Y - a.X, q = b.Y - b.X, w = b.X - a.X;
        LL x, y, d, z, c;
        d = extgcd(p, q, x, y);
        if (w % d) {
            puts("-1");
            continue;
        }
        x = w / d * x, y = w / d * y;
        y =- y;
       // sc3(p, q, w);
        //sc2(x, y);
        if (x > 0) {
            c = x / (q / d);
            x -= c * (q / d);
            y -= c * (p / d);
            while (x > 0) x -= q / d, y -= p / d;
        }
        if (x < 0) {
            c = (-x) / (q / d);
            x += c * (q / d);
            y += c * (p / d);
            while (x < 0) x += q / d, y += p / d;
        }
        if (y < 0) {
            c = (-y) / (p / d);
            x += c * (q / d);
            y += c * (p / d);
            while (y < 0) x += q / d, y += p / d;
        }
        cout << a.X + x * (a.Y - a.X) << '\n';
    }
    return 0;
}





















