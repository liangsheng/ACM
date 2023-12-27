#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-x))
using namespace std;
typedef long long LL;

const int P = 107, MOD = 998244353;
// const int P = 16351717;

/*------------------------------- 树状数组 begin ---------------------------*/
int n;
vector<int> a, b;

void init_lowbit(int n) {
    a = vector<int>(n + 2, 0);
    b = vector<int>(n + 2, 0);
}

void update(vector<int>& a, int p, int val, int f) {
    for (; p >= 1 && p <= n; p += lowbit(p) * f) a[p] = (a[p] + val) % MOD;
}

int query(vector<int>& a, int p, int f) {
    int ans = 0;
    for (; p >= 1 && p <= n; p += lowbit(p) * f) {
        ans = (ans + a[p]) % MOD;
    }
    return ans;
}
/*------------------------------- 树状数组 end -----------------------------*/

/*------------------------------- 字符串 hash begin ------------------------*/

vector<int> L, R, d;

void init(string& s) {
    n = s.size();
    d = vector<int>(n, 1);
    for (int i = 1; i < n; i++) d[i] = (LL) d[i - 1] * P % MOD;

    L = vector<int>(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        L[i] = (L[i - 1] + (LL) d[i - 1] * (s[i - 1] - 'a')) % MOD;
    }

    R = vector<int>(n + 2, 0);
    for (int i = n; i >= 1; i--) {
        R[i] = (R[i + 1] + (LL) d[n - i] * (s[i - 1] - 'a')) % MOD;
    }
}

bool ok(int i, int j) {
    int lj = query(a, j, -1), li = query(a, i - 1, -1);
    int x = ((LL) d[n - j] * (L[j] - L[i - 1] + lj - li) % MOD + MOD) % MOD;

    int ri = query(b, i, 1), rj = query(b, j + 1, 1);
    int y = ((LL) d[i - 1] * (R[i] - R[j + 1] + ri - rj) % MOD + MOD) % MOD; 
    return x == y;
}
/*------------------------------- 字符串 hash end --------------------------*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, c, l, r;
    char ch;
    string s;
    while (cin >> n >> m) {
        cin >> s;
        init(s);
        init_lowbit(n);
        while (m--) {
            cin >> c;
            if (c == 2) {
                cin >> l >> r;
                cout << (ok(l, r) ? "Yes" : "No") << '\n';
            } else {
                cin >> l >> ch;
                int D = ((LL) d[l - 1] * (ch - s[l - 1]) % MOD + MOD) % MOD;
                update(a, l, D, 1);

                D = ((LL) d[n - l] * (ch - s[l - 1]) % MOD + MOD) % MOD;
                update(b, l, D, -1);

                s[l - 1] = ch;
            }
        }
    }
    return 0;
}