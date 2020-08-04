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
#define sqr(x) ((x) * (x))

#define sc(n) cout << #n << "= " << n, system("pause")
#define sc2(n, m) cout << #n << "= " << n << " " << #m << "= " << m, system("pause")
#define sc3(n, m, k) cout << #n << "= " << n << " " << #m << "= " << m << " " << #k << "= " << k, system("pause")
#define sc4(n, m, k, b) cout << #n << "= " << n << " " << #m << "= " << m << " " << #k << "= " << k << " " << #b << "= " << b, system("pause")

using namespace std;
int chh;

typedef long long LL;

const int N = 200005;

int n;
string a, b;

bool ok(string a, string b) {
    if (a == b) return 1;
    int n = a.size();
    if (n % 2) return 0;
    string a1 = a.substr(0, n / 2), a2 = a.substr(n / 2, n / 2);
    string b1 = b.substr(0, n / 2), b2 = b.substr(n / 2, n / 2);
    if (ok(a1, b1) && ok(a2, b2)) return 1;
    if (ok(a1, b2) && ok(a2, b1)) return 1;
    return 0;
}

int main() {
    while (cin >> a >> b) {
        n = a.size();
        bool f = ok(a, b);
        puts(f ? "YES" : "NO");
    }
    return 0;
}










