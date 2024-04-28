#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 100005, D = 350;
const LL INF = numeric_limits<LL>::max() / 2;

int n, d, m, MOD;
int a[N];    // 原数组
int mul[D];  // 块里的数都要乘上的数
int add[D];  // 块里的数都要加上的数
int s[D];    // 块里的数的和
int id[N];   // 块号

void init(int n) {
    d = sqrt(n), m = (n + d - 1) / d;
    for (int i = 0; i < m; i++) s[i] = 0, mul[i] = 1, add[i] = 0;
    for (int i = 0; i < n; i++) {
        id[i] = i / d;
        s[id[i]] = (s[id[i]] + a[i]) % MOD; 
    }
}

// 将第 p 块的 tag 下放
void reset(int p) {
    if (mul[p] == 1 && add[p] == 0) return ;
    int l = p * d, r = min(n, l + d) - 1;
    for (int i = l; i <= r; i++) a[i] = ((LL) a[i] * mul[p] + add[p]) % MOD;
    mul[p] = 1, add[p] = 0;
}

// 单点更新
void update_p(int p, int x, int y) {
    // int d = ((LL) a[p] * x + y) % MOD;
    // s[id[p]] = ((LL) s[id[p]] + d - a[p] + MOD) % MOD;
    // a[p] = d;
    if (x != 1) {
        int d = (LL) a[p] * x % MOD;
        s[id[p]] = ((LL) s[id[p]] + d - a[p] + MOD) % MOD;
        a[p] = d;
    } else if (y != 0) {
        int d = (a[p] + y) % MOD;
        s[id[p]] = (s[id[p]] + d - a[p] + MOD) % MOD;
        a[p] = d;
    }
}

// 区间更新
void update_r(int p, int x, int y) {
    // int l = p * d, r = min(n, l + d) - 1;
    // s[p] = ((LL) s[p] * x + (LL) y * (r - l + 1)) % MOD;
    // add[p] = ((LL) add[p] * x + y) % MOD; 
    // mul[p] = (LL) mul[p] * x % MOD;
    int l = p * d, r = min(n, l + d) - 1;
    if (x != 1) {
        s[p] = (LL) s[p] * x % MOD;
        add[p] = (LL) add[p] * x % MOD; 
        mul[p] = (LL) mul[p] * x % MOD;
    } else if (y != 0) {
        s[p] = (s[p] + (LL) y * (r - l + 1)) % MOD;
        add[p] = (add[p] + y) % MOD;
    }
}

// 将 [l, r] 乘 x 加 y
void update(int l, int r, int x, int y) {
    // reset(id[l]), reset(id[r]);
    // if (id[l] == id[r]) {
    //     for (int i = l; i <= r; i++) update_p(i, x, y);
    // } else {
    //     for (int i = l; id[i] == id[l]; i++) update_p(i, x, y);  // 左边多余的部分
    //     for (int i = r; id[i] == id[r]; i--) update_p(i, x, y);  // 右边多余的部分
    //     for (int i = id[l] + 1; i < id[r]; i++) update_r(i, x, y);
    // }

    if (id[l] == id[r]) {
        reset(id[l]);
        for (int i = l; i <= r; i++) update_p(i, x, y);
    } else {
        if (l % d != 0) {
            reset(id[l]);
            for (int i = l; id[i] == id[l]; i++) update_p(i, x, y);  // 左边多余的部分
        }
        if (r % d != d - 1) {
            reset(id[r]);
            for (int i = r; id[i] == id[r]; i--) update_p(i, x, y);  // 右边多余的部分
        }
        int L = id[l] + (l % d > 0), R = id[r] - (r % d != d - 1);
        for (int i = L; i <= R; i++) update_r(i, x, y);
    }
}

int query(int l, int r) {
    // reset(id[l]), reset(id[r]);
    // int ans = 0;
    // if (id[l] == id[r]) {
    //     for (int i = l; i <= r; i++) ans = (ans + a[i]) % MOD;
    // } else {
    //     for (int i = l; id[i] == id[l]; i++) ans = (ans + a[i]) % MOD; // 左边多余的部分
    //     for (int i = r; id[i] == id[r]; i--) ans = (ans + a[i]) % MOD;  // 右边多余的部分
    //     for (int i = id[l] + 1; i < id[r]; i++) ans = (ans + s[i]) % MOD;
    // }
    // return ans;

    int ans = 0;
    if (id[l] == id[r]) {
        for (int i = l; i <= r; i++) ans = (ans + (LL) a[i] * mul[id[i]] + add[id[i]]) % MOD;
    } else {
        for (int i = l; id[i] == id[l]; i++) ans = (ans + (LL) a[i] * mul[id[i]] + add[id[i]]) % MOD; // 左边多余的部分
        for (int i = r; id[i] == id[r]; i--) ans = (ans + (LL) a[i] * mul[id[i]] + add[id[i]]) % MOD;  // 右边多余的部分
        for (int i = id[l] + 1; i < id[r]; i++) ans = (ans + s[i]) % MOD;
    }
    return ans;
}

// namespace IO {
    template <typename T>
    inline void w(T x) { if (x > 9) w(x / 10); putchar(x % 10 + 48); }
    template <typename T>
    inline void write(T x, char c) { if(x < 0) putchar('-'), x = -x; w(x); putchar(c); }
    template <typename T>
    inline void read(T &x) {
        x = 0; T f = 1; char c = getchar();
        for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
        for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
        x *= f;
    }
// };

int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    clock_t start, finish;
    start = clock();

    freopen("P3373_2.in", "r", stdin);
    freopen("P3373_2.out", "w", stdout);

    int q, c, l, r, x;
    cin >> n >> q >> MOD;
    // scanf("%d %d %d", &n, &q, &MOD);
    // read(n), read(q), read(MOD);
    for (int i = 0; i < n; i++) cin >> a[i];
    // for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    // for (int i = 0; i < n; i++) read(a[i]);

    init(n);
    while (q--) {
        cin >> c;
        if (c == 1) {
            cin >> l >> r >> x;
            // scanf("%d %d %d", &l, &r, &x);
            // read(l), read(r), read(x);
            update(l - 1, r - 1, x, 0);
        } else if (c == 2) {
            cin >> l >> r >> x;
            // scanf("%d %d %d", &l, &r, &x);
            // read(l), read(r), read(x);
            update(l - 1, r - 1, 1, x);
        } else {
            cin >> l >> r;
            // scanf("%d %d", &l, &r);
            // read(l), read(r);
            cout << query(l - 1, r - 1) << "\n";
            // printf("%d\n", query(l - 1, r - 1));
            // w(query(l - 1, r - 1));
            // puts("");
        }
    }

    finish = clock();
    cout << fixed << setprecision(8) << double(finish - start) / 1000 << '\n';
    return 0;
}