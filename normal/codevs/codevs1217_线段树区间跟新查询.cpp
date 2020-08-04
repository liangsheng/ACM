#include <bits/stdc++.h>

#define file_r(x) freopen(x, "r", stdin)
#define file_w(x) freopen(x, "w", stdout)
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
#define ins insert

#define sc(n) cout << #n << "= " << n, system("pause")
#define sc2(n, m) cout << #n << "= " << n << " " << #m << "= " << m, system("pause")
#define sc3(n, m, k) cout << #n << "= " << n << " " << #m << "= " << m << " " << #k << "= " << k, system("pause")
#define sc4(n, m, k, b) cout << #n << "= " << n << " " << #m << "= " << m << " " << #k << "= " << k << " " << #b << "= " << b, system("pause")

using namespace std;
int chh;

typedef long long LL;

template<class T>
inline char read(T &n){
    T x = 0, tmp = 1; char c = getchar();
    while ((c < '0' || c > '9') && c != '-' && c != EOF) c = getchar();
    if (c == '-') c = getchar(), tmp = -1;
    while (c >= '0' && c <= '9') x *= 10, x += (c - '0'), c = getchar();
    n = x * tmp;
    return c;
}

template <class T>
inline void write(T n) {
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    int len = 0,data[20];
    while (n) {
        data[len++] = n%10;
        n /= 10;
    }
    if (!len) data[len++] = 0;
    while (len--) putchar(data[len] + 48);
}

const int N = 1000005, INF = ~0U >> 1;

int n, m, M;
int a[N * 4], b[N * 4], h[N];

void push_up(int k) {
    a[k] = min(a[k << 1], a[k << 1 | 1]);
}

void init(int k, int s, int t) {
    b[k] = 0;
    if (s == t) a[k] = h[s];
    else {
        int mid = (s + t) >> 1;
        init(k << 1, s, mid);
        init(k << 1 | 1, mid + 1, t);
        push_up(k);
    }
}

void push_down(int k) {
    if (b[k] == 0) return ;
    int l = k << 1, r = k << 1 | 1;
    a[l] += b[k], b[l] += b[k];
    a[r] += b[k], b[r] += b[k];
    b[k] = 0;
}

bool update(int k, int s, int t, int l, int r, int f) {
    if (r < s || l > t) return 1;
    if (s >= l && t <= r) {
        a[k] += f;
        b[k] += f;
        if (a[k] < 0) return 0;
        return 1;
    }
    push_down(k);
    int mid = (s + t) >> 1;
    bool flag = update(k << 1, s, mid, l, r, f);
    flag &= update(k << 1 | 1, mid + 1, t, l, r, f);
    push_up(k);
    return flag;
}

int gao(int k, int s, int t, int l, int r) {
    if (r < s || l > t) return INF;
    if (s >= l && t <= r) return a[k];
    push_down(k);
    int mid = (s + t) >> 1, ans;
    ans = min(gao(k << 1, s, mid, l, r), gao(k << 1 | 1, mid + 1, t, l, r));
    return ans;
}

int main() {
    int d, s, t, c, flag;
    read(n), read(m);
    FOR (i, 1, n) read(h[i]);
    init(1, 1, n);
    FOR (k, 1, m) {
        read(d), read(s), read(t);
        //c = gao(1, 1, n, s, t);
        //sc(c);
        flag = update(1, 1, n, s, t, -d);
        if (!flag) {
            write(-1), puts(""), write(k), puts("");
            return 0;
        }
    }
    puts("0");
    return 0;
}

